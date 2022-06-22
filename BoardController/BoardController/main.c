/*
 * BoardController.c
 *
 * Created: 18.06.2022 15:00:42
 * Author : Kalle Bracht
 *
 * TODO:
 *	Interrupt for:
 *		- Speed -> INT4/PE4/D2
 *		- If brake -> INT5/PE5/D3
 *		- If lap trigger -> INT3/PD3/D18
 * Information for (send):
 *		- Battery voltage -> ADC8/PCINT16/PK0/A8 
 *		- Engine temp -> ADC9/PCINT17/PK1/A9
 *      - Used current -> ADC10/PCINT18/PK2/A10
 *      - Generated current -> ADC11/PCINT19/PK3/A11
 *
 * Serial connection:
 *		- TX(3) -> PCINT10/PJ1/D14 
 *      - RX(3) -> PCINT9/PJ0/D15
 *
 * Optimization:
 *		- Combining ACD read and avarge_read so that the registers will not overwrite all the time 
 *		- Flag system to avoid bool 
 *      - Speed event not 0x00
 *      - Real baud rate is not right
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#define F_CPU 16000000UL
#define BAUD_RATE 115200UL

#define UBRR_VAL ((F_CPU + BAUD_RATE * 8) / (BAUD_RATE * 16) - 1)


#define SPEED_TRIGGER 0x00
#define LAP_TRIGGER   0x01
#define BRAKE_TRIGGER 0x02
#define INFO_TRIGGER  0x03

#define BATTERY_VOLTAGE_PIN   0x20
#define ENGINE_TEMP_PIN       0x21
#define USED_CURRENT_PIN      0x22
#define GENERATED_CURRENT_PIN 0x23

#define ADC_SAMPLE_COUNT 10  //Max: 255 -> uint8_t

//A flag which indicates if at this point of time data more than one byte is transmitted(info).
//This is for the interrupts to not send there trigger within a information. That would cause chaos
bool now_on_info_send = false;

//This is a stack for pending triggers to send if they can't because a info send in the way 
volatile trigger_stack[5] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
//For the send_trigger() to know where to put the trigger in the trigger stack
volatile trigger_count = 0;

//Is set before send begins
void start_info_send(){
	now_on_info_send = true;
}

//Is set after send and looks if there where interrupts to send
void end_info_send(){
	now_on_info_send = false;
	for(uint8_t i = 0; i < sizeof(trigger_stack)/sizeof(trigger_stack[0]); i++){  //Checking the stack
		if(trigger_stack[i] != 0xFF){
			send_trigger(trigger_stack[i]);
			trigger_stack[i] = 0xFF;  //Setting the value back to default 0xFF
		} else {
			trigger_count = 0;
			break;		
		}
	}
}

//Sending the data of the trigger over the third USART register
void send_trigger(uint8_t id){
	if(now_on_info_send){  //Check if it is possible to send directly via UART
		while(!(UCSR3A & (1<<UDRE3))){}  //Wait until sending is possible
		UDR3 = id;  //Sending one uint8_t/char via UDR3 register
	} else {
		trigger_stack[trigger_count] = id;  //Adding trigger to trigger_stack, the trigger will be send the next possible situation 
		trigger_count++;
	}
}

//Sends a buffer/array of values(uint8_t/char) to UART3
void send_buf(uint8_t *buf){
	start_info_send();  //Setting flag to true because the buffer send begins now
	while(*buf){
		while(!(UCSR3A & (1<<UDRE3))){}  //Wait until sending is possible
		UDR3 = *buf;  //Sending one uint8_t/char via UDR3 register
		buf++;
	}
	
	end_info_send();  //Finish with sending, ending and looking in end_info_send() if anything in trigger_stack
}


void send_info(float info){
	uint8_t buf[5];
	buf[0] = 0x03;
	memcpy(buf + 1, (uint8_t*)(&info), 5);  //Casting trigger ID(3) and float to buffer
	send_buf(&buf);
}


//Implementation of function to read ADC in "single conversion" mode
uint16_t ADC_read(uint8_t pin){
	ADMUX = (ADMUX & ~(0x1F)) | (pin & 0x1F);  //Setting the pin which the ADC should read
	ADCSRA |= (1<<ADSC);  // "single conversion" measure (not measurement series into register)
	while(ADCSRA & (1<<ADSC)) {}  //Wait till "single conversion" is fully configured by Atmel
	return ADCW;  //Return output register of ADC
}

//Calculates the average ADC value of count of samples <- defined in macro above
uint16_t average_read(uint8_t pin){
	uint32_t sum = 0;
	for(uint8_t i = 0; i < ADC_SAMPLE_COUNT; i++){
		sum += ADC_read(pin);
	}
	
	return (uint16_t)(sum / ADC_SAMPLE_COUNT);
}

//Interrupt for speed trigger
ISR(INT4_vect, ISR_NOBLOCK){
	send_trigger(SPEED_TRIGGER);  //Writing to UART
}

//Interrupt for brake trigger
ISR(INT5_vect, ISR_NOBLOCK){
	send_trigger(BRAKE_TRIGGER);  //Writing to UART
}

//Interrupt for lap trigger
ISR(INT3_vect, ISR_NOBLOCK){
	send_trigger(LAP_TRIGGER); //Writing to UART
}


int main(void){
	//INIT UART for the third register
	UCSR3B |= (1 << TXEN3);  //Enable tx
	UCSR3B |= (1 << RXEN3);  //Enable rx
	
	UCSR3C |= (1 << UCSZ30) | (1 << UCSZ31);  //Set frame format to 8 data bits (and 1 stop bit)
	UBRR3H = UBRR_VAL >> 8;  //Setting baud rate
	UBRR3L = UBRR_VAL & 0xFF;  //Setting baud rate
	
	
	//INIT ADC
	ADMUX = (1 << REFS0);  //Setting the ref voltage to AVcc -> 5V
	ADCSRA = (1 << ADPS1) | (1 << ADPS0);  //Setting division factor of ADC to 8. See https://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/Analoge_Ein-_und_Ausgabe
	ADCSRA |= (1 << ADEN);
	(void) ADCW;  //Reading ADCW (ADC output register) to clear for next measure
	
    sei();  //Allowing interrupts, maybe change with "<util/atomic.h>"
	
    while(1){
		uint16_t battery_volatage_m = ADC_read(BATTERY_VOLTAGE_PIN);
		//Calc stuff 
		send_info(1.2433f);
		
		uint16_t engine_temp_m = ADC_read(ENGINE_TEMP_PIN);
		//Calc stuff 
		send_info(1.2433f);
		
		uint16_t used_current_m = ADC_read(USED_CURRENT_PIN);
		//Calc stuff 
		send_info(1.2433f);
		
		uint16_t generated_current_m = ADC_read(GENERATED_CURRENT_PIN);
		//Calc stuff 
		send_info(1.2433f);
    }
}


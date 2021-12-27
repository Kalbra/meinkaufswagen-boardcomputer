#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include <assert.h>

//Checks what portname to use
#ifdef _WIN32
    #define SERIAL_PORT_NAME "COM5"
#elif linux
    #define SERIAL_PORT_NAME "/dev/ttyAMA0"
#else
    assert(0, "Cant specify which os is used");
#endif

#define WHEEL_CIRCUMFERENCE 20//IN CM
#define SERIAL_TIME_OFFSET -0.01//IN SEC
#define MAX_RPM 1000
#define MIN_RPM 3000
#define RPM_MULTIPLYER 3


#endif // DEFINITIONS_H

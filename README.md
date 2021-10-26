# Meinkaufswagen Boardcomputer

![Custom Size – 1](https://user-images.githubusercontent.com/42813640/138115646-2b979ced-8770-4fd1-91bc-3f7921b098bd.png)


- Lenkrad:
  -	Knöpfe
    -	Menü wechseln(Rot, links, 1)
    -	Tempomat ein/aus(Grün, rechts, 2)
    -	Tempomat hoch(Grün, links, 2)
    -	Tempomat runter(Grün, links,3)
    -	Lap trigger(Rot, rechts, 1)
    -	Licht ein/aus(Gelb, rechts, 3)
  -	Paddel
    -	Gas

- Serial read von Lenkrad aus:
  -	(double) Batterieladestand
  -	(bool) Rundentrigger
  -	(bool) Bremsentrigger

- Serial write von Lenkrad aus:
  -	(uint16_t) Gas
  -	(bool) Light on/off

---------------

Structur read:
| Type     |Baterieladestand(nur bei Info)|
|----------|----------------|
| uint8_t  |   double       |
|     0    | 1 \| 2 \| 3 \| 4 \| 5 \| 6 \| 7 \| 8 | 

Types:
- 0: Speed event
- 1: Lap event
- 2: Bremse event
- 3: Information

---------------

Structur send:
| Gas      |Licht on/off|
|----------|------------|
| uint16_t |   bool     |
|  0 \| 1  |     2      | 


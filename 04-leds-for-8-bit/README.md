## Flash LEDs for 8 bit binary data

In main.h file, define GPIO Pins 0 (GPIO_PIN_0) to Pins 7 (GPIO_PIN_7) for LED0 to LED7.

Try to flash LEDs for 8 bit binary data.

## Process steps
Use a bit array to present an integer number to 8-bit flashing LEDs.

This table is the bit status of integer number 9.

2<sup>3</sup> + 2<sup>0</sup> = 9

When the bit status is 1, turn on LED.

| Bit Position | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|---|---|---|---|---|---|---|---|---|
| Bit Status | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 1 |
| Flash LED | off | off | off | off | on | off | off | on |


Step 1: Set the bit position like a array mask.

Step 2: Use AND (&) to convert every bit status with the integer number.

Step 3: Shift left bit position by 1.

Step 4: Add integer number by 1.

Step 5: Set the integer number to 0 when it was 255.

Step 6: Delay.

Repeat these steps.
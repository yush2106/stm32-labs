## Flash random leds for 8 bit data

Define the 8 GPIO pins, Pin0 (GPIO_PIN_0) to Pin7 (GPIO_PIN_7), for LED0 to LED7 in main.h file.

Generate a random number, then turn on LEDs for the 8 bit data of the random number.

## Process steps
Step 1: Include standard library for generating random number.

Step 2: Generate a random number and calculate the remainder.

Step 3: Set the bit position like a array mask.

Step 4: Use AND (&) to convert every bit status with the random number.

Step 5: Delay.
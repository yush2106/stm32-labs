## Display numbers on 4 digit 7 segment display

Connect to GPIO pin 0 to pin 10, PC0 to PC10, with 4 digit 7 segment display.

7 segment display LEDs are connected with PC0 to PC6.

The pins, PC7 to PC10, drive each digit display.

## Process steps

Step 1: Define the enabled signals array for 4 digits.

Step 2: Define the hexadecimal numbers array for registers.

Step 3: Define the display number.

Step 4: Convert each digit number for the display number.

Step 5: Write digit number to registers.

Step 6: Enable digit for 4 digit 7 segment display.

Step 7: Delay.

Step 8: Disable digit for 4 digit 7 segment display.

Complete the 4 digit number continuously.

![image](https://github.com/yush2106/stm32-labs/blob/main/15-four-digit-7-segment-display/img/15-four-digit-7-segment-display-01.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/15-four-digit-7-segment-display/img/15-four-digit-7-segment-display-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/15-four-digit-7-segment-display/img/15-four-digit-7-segment-display-03.jpg)
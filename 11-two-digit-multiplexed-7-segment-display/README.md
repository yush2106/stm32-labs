## Using 7 Segment Display for Multiplexed 2 digit numbers

To enable digits signal, connect the BJT part, 2N2222A, to GPIO Pin7 and Pin8, PC7 and PC8.

Display each digit number in every short time period for 4 digit 7 segment display.

## Process steps

Step 1: Define the display number.

Step 2: Reset the digit pins.

Step 3: Write digit1 number to output data register.

Step 4: Set the digit pins enabled.

Step 5: Delay for a short time period.

Step 6: Set the digit pins disabled.

Step 7: Write digit1 number to output data register.

Step 8: Set the digit pins enabled.

Step 9: Delay for a short time period.

Step 10: Set the digit pins disabled.

4-digit 7 segment display pins

![image](https://github.com/yush2106/stm32-labs/blob/main/11-two-digit-multiplexed-7-segment-display/img/11-two-digit-multiplexed-7-segment-display-01.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/11-two-digit-multiplexed-7-segment-display/img/11-two-digit-multiplexed-7-segment-display-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/11-two-digit-multiplexed-7-segment-display/img/11-two-digit-multiplexed-7-segment-display-03.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/11-two-digit-multiplexed-7-segment-display/img/11-two-digit-multiplexed-7-segment-display-04.jpg)
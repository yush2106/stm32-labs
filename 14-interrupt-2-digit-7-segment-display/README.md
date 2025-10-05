## Interrupt counter on 2 digit 7 segment display

The onboard button, pin PC13, is used for interrupt signal.

Connect GPIO pins 0 to pins 6, PC0 to PC6, for 2 digit 7 segment display.

Increase the counter number on 2 digit 7 segment display when the onboard button is pressed.

## Process steps

Step 1: Set the onboard button, pin PC13, for **External Interrupt Mode with Falling edge trigger detection**.

Step 2: Set the **EXTI line[15:10] interrupts** enabled and set the **Preemption Priority** and **Sub Priority** to 0.

Step 3: Define pin PC7 for digit1 and pin PC8 for digit2.

Step 4: Define an array for hexadecimal number of the register.

Step 5: When the interrupt signal inputs, the callback function increase the counter number.

Step 6: Extract the MSB number of counter, enable the digit1 of 2 digit 7 segment display.

Step 7: Delay.

Step 8: Disable the digit1.

Step 9: Extract the LSB number of counter, display the digit2 of 2 digit 7 segment display.

Step 10: Delay.

Step 11: Disable the digit2.

![image](https://github.com/yush2106/stm32-labs/blob/main/14-interrupt-2-digit-7-segment-display/img/14-interrupt-2-digit-7-segment-display-01.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/14-interrupt-2-digit-7-segment-display/img/14-interrupt-2-digit-7-segment-display-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/14-interrupt-2-digit-7-segment-display/img/14-interrupt-2-digit-7-segment-display-03.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/14-interrupt-2-digit-7-segment-display/img/14-interrupt-2-digit-7-segment-display-04.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/14-interrupt-2-digit-7-segment-display/img/14-interrupt-2-digit-7-segment-display-05.jpg)
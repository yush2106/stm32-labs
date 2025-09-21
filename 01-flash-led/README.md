## Flashing onboard LED

In the main.h file, define the Pin5 (GPIO_PIN_5) of GPIO group A (GPIOA) for flashing onboard LED.

In the main.c file, The "turn on" pin status is "SET" (GPIO_PIN_SET), and "turn off" pin status is "RESET" (GPIO_PIN_RESET).

## Process steps
Step 1: Trun on LED.

Step 2: Delay.

Step 3: Trun off LED.

Step 4: Delay.

![image](https://github.com/yush2106/stm32-labs/blob/main/01-flash-led/img/01-flash-led.jpg)
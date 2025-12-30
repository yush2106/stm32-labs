## FreeRTOS

This project, use FreeRTOS structure to build 3 tasks to turn on or turn off the LEDs. Ecah task has its timing process to control the LEDs.

## Process Step

Step 1: Set PB0 to PB2 are GPIO Output.

![image](https://github.com/yush2106/stm32-labs/blob/main/50-freertos/img/50-freertos-01.jpg)

Step 2: FreeRTOS settings

Interface: **CMSIS_V2**

![image](https://github.com/yush2106/stm32-labs/blob/main/50-freertos/img/50-freertos-02.jpg)

Step 3: Circuits diagram

![image](https://github.com/yush2106/stm32-labs/blob/main/50-freertos/img/50-freertos-03.jpg)

Step 4: Execute tasks at the same time

Each thread task has its own timing process to drive the LEDs to turn on or turn off.

![image](https://github.com/yush2106/stm32-labs/blob/main/50-freertos/img/50-freertos-04.jpg)
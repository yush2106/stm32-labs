## Use the external interrupt signal to control LED

Define the onboard button, Pin 13 (PC13), for an interrupt signal.

Toggle the onboard LED, Pin 5 (PA5), when the onboard button is pressed.

## Process steps

Step 1: Set the Pin PC13 for EXTI (external interrupt) mode, and set Pin PA5 for GPIO output mode.

Step 2: Configure PC13 to __External Interrupt Mode with Falling edge trigger detection__.

Step 3: Enable the EXTI line[15:10] interrupts, set Preemption Priority to 0 and Sub Priority to 0.

Step 4: Create the __HAL_GPIO_EXTI_Callback__ function to toggle LED.

Step 5: Pressed the onboard button to turn on or turn off the onboard LED.

![image](https://github.com/yush2106/stm32-labs/blob/main/12-led-for-external-interrupt/img/12-led-for-external-interrupt-01.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/12-led-for-external-interrupt/img/12-led-for-external-interrupt-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/12-led-for-external-interrupt/img/12-led-for-external-interrupt-03.jpg)
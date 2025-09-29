## Multiple Interrupts to control LEDs

Set the 2 buttons for external interrupts, button1 is connected to Pin6 (PA6), button2 is connected to Pin7 (PA7).

Toggle the 2 LEDs, LED1 (PA13) and LED2 (PA14), when the interrupt signals input.

## Process steps

Step 1: Set Pin PA6 and PA7 for EXTI (external interrupt) mode.

Step 2: Set Pin PA13 and PA14 for GPIO output mode.

Step 3: Configure PA6 and PA7 to __External Interrupt Mode with Falling edge trigger detection__.

Step 4: Enable the EXTI line[9:5] interrupts, set Preemption Priority to 0 and Sub Priority to 0.

Step 5: Create the __HAL_GPIO_EXTI_Callback__ function, toggle each LED when the interrupts input.

![image](https://github.com/yush2106/stm32-labs/blob/main/13-multiple-external-interrupts/img/13-multiple-external-interrupts-01.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/13-multiple-external-interrupts/img/13-multiple-external-interrupts-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/13-multiple-external-interrupts/img/13-multiple-external-interrupts-03.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/13-multiple-external-interrupts/img/13-multiple-external-interrupts-04.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/13-multiple-external-interrupts/img/13-multiple-external-interrupts-05.jpg)
## Up Down Counter on 4 digit 7 segment display by interrupted buttons.

Connteced 2 buttons for inturrupt inputs, the 2 pins are PA0 and PA1.

The 7 segment display LEDs connect to pins PC0 to PC6, and the 4 digit enabled input pins are PC7 to PC10.

Increase or decrease the counter number when pressing the 2 inturrupted buttons.

## Process steps

Step 1: Set PA0 and PA1 for **External Interrupt**, and set the GPIO mode **External Interrupt Mode with Falling edge trigger detection**.

Step 2: Enable the **EXTI line0 interrupt** and **EXTI line1 interrupt**, then set the **Preemption Priority** and **Sub Priority** to zero.

Step 3: Set PC0 to PC10 for GPIO_Output pins.

Step 4: The 4 digit enabled pins connect with the BJT part, **2N2222A**.

Step 5: The IRQHandler of PA0 and PA1 are generated in the file **stm32l4xx_it.c**.

Step 6: When the interrupted buttons pressed, increase or decrease counter number in the **HAL_GPIO_EXTI_Callback** function.

Step 7: Exteact the 4 digit numbers, write to registers.

Step 8: delay.

Complete the 4 digit numbers continuously.

![image](https://github.com/yush2106/stm32-labs/blob/main/16-interrupt-up-down-counter-4-digit/img/16-interrupt-up-down-counter-4-digit-01.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/16-interrupt-up-down-counter-4-digit/img/16-interrupt-up-down-counter-4-digit-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/16-interrupt-up-down-counter-4-digit/img/16-interrupt-up-down-counter-4-digit-03.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/16-interrupt-up-down-counter-4-digit/img/16-interrupt-up-down-counter-4-digit-04.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/16-interrupt-up-down-counter-4-digit/img/16-interrupt-up-down-counter-4-digit-05.jpg)
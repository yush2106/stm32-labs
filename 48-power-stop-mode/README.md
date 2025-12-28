## Power Management for Stop Mode

Set the NUCLEO-L476RG is stop mode.

When the onboard button is clicked, it's interrupt operation will be triggered to restart the system clock and toggle the onboard LED.

In stop mode, the CPU clock is OFF and the system clock is Off, too.

## Process Step

Step 1: Configure the onboard button and onboard LED

Set onboard button pin PC13 is GPIO_EXTI13.

Set onboard LED pin PA5 is GPIO_Output.

![image](https://github.com/yush2106/stm32-labs/blob/main/12-led-for-external-interrupt/img/12-led-for-external-interrupt-01.jpg)

Step 2: Onboard button pin PC13 settings

![image](https://github.com/yush2106/stm32-labs/blob/main/12-led-for-external-interrupt/img/12-led-for-external-interrupt-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/12-led-for-external-interrupt/img/12-led-for-external-interrupt-03.jpg)

Step 3: Create the HAL_GPIO_EXTI_Callback function to restart system clock and toggle LED

Step 4: Start Stop Mode

Start **HAL_PWR_EnableSleepOnExit()** function and **HAL_PWR_EnterSTOPMode()** function.

Set the **PWR_SLEEPENTRY_WFI** parameter to wait for interrupt.

Step 5: Wake up from stop mode

When the onboard button is clicked, the onboard LED will be turn on or turn off.

![image](https://github.com/yush2106/stm32-labs/blob/main/06-push-button-led/img/06-push-button-led-01.jpg)
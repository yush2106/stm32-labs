## Power Management for Sleep Mode

Set the NUCLEO-L476RG is sleep mode.

When the onboard button is clicked, it's interrupt operation will be triggered to toggle the onboard LED.

In sleep mode, the CPU clock is OFF, but the system clock is still On.

## Process Step

Step 1: Configure the onboard button and onboard LED

Set onboard button pin PC13 is GPIO_EXTI13.

Set onboard LED pin PA5 is GPIO_Output.

![image](https://github.com/yush2106/stm32-labs/blob/main/12-led-for-external-interrupt/img/12-led-for-external-interrupt-01.jpg)

Step 2: Onboard button pin PC13 settings

![image](https://github.com/yush2106/stm32-labs/blob/main/12-led-for-external-interrupt/img/12-led-for-external-interrupt-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/12-led-for-external-interrupt/img/12-led-for-external-interrupt-03.jpg)

Step 3: Create the HAL_GPIO_EXTI_Callback function to toggle LED

Step 4: Start Sleep Mode

Start **HAL_PWR_EnableSleepOnExit()** function and **HAL_PWR_EnterSLEEPMode()** function.

Set the **PWR_SLEEPENTRY_WFI** parameter to wait for interrupt.

Step 5: Wake up from sleep mode

When the onboard button is clicked, the onboard LED will be turned on or turned off.

![image](https://github.com/yush2106/stm32-labs/blob/main/06-push-button-led/img/06-push-button-led-01.jpg)
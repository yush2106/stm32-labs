## Power Management for Standby Mode

In this project, set NUCLEO-L476RG is standby mode.

There's a physical wakeup pin, PA0, built on NUCLEO-L476RG.

## Process Step

Step 1: Set the onboard LED pin PA0 is GPIO Output

![image](https://github.com/yush2106/stm32-labs/blob/main/49-power-standby-mode/img/49-power-standby-mode-01.jpg)

Step 2: Clear the PWR_FLAG_SB and disable PWR_WAKEUP_PIN1, PA0, when wakeup event occured.

Turn on the onboard LED at the same time.

Step 3: Clear the PWR_FLAG_WU and enable PWR_WAKEUP_PIN1 before entering standby mode.

Turn off the onboard LED and enter standby mode.
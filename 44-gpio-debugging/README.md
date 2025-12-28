## GPIO Debugging

In this project, configure the Serial Wire Debug (SWD) settings to monitor GPIO staus.

Set the onboard LED PA5 pin for debugging.

## Process Step

Set PA13, PA14 for Serial Wire Debug (SWD) pins.

Set PA5 for onboard LED GPIO Output pin.

![image](https://github.com/yush2106/stm32-labs/blob/main/44-gpio-debugging/img/44-gpio-debugging-01.jpg)

Step 1: Serial Wire settings

Debug: **Serial Wire**

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-02.jpg)

Step 2: Project Properties

Project -> Properties

C/C++ Build -> Settings -> MCU/MPU GCC Compiler -> Optimization

Optimization Level: **None (-O0)**

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-04.jpg)

C/C++ Build -> Settings -> MCU/MPU GCC Compiler -> Debugging

Debug Level: **Maximun (-g3)**

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-05.jpg)

Step 3: Debug Mode

Project -> Build Configurations -> Set Active -> Debug

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-07.jpg)

Step 4: Set the break points

![image](https://github.com/yush2106/stm32-labs/blob/main/44-gpio-debugging/img/44-gpio-debugging-02.jpg)

Step 5: Run debug

Run -> Debug As -> 1 STM32 C/C++ Application

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-08.jpg)

Build Configuration: **Debug**

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-09.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-10.jpg)

Step 6: Check the current GPIO register value

When the process stop at the break point, check the register value of the GPIO ODR port.

![image](https://github.com/yush2106/stm32-labs/blob/main/44-gpio-debugging/img/44-gpio-debugging-03.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/44-gpio-debugging/img/44-gpio-debugging-04.jpg)
## Simple Debug Settings

Configure the **Serial Wire** for debugging in the STM32 development project.

When debug mode is enabled, we could set the break point to check the parameters and execute the program process step by step.

## Process Step

Set PA13, PA14 for Serial Wire Debug (SWD) pins.

Set PA2, PA3 for UART pins.

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-01.jpg)

Step 1: Serial Wire settings

Debug: **Serial Wire**

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-02.jpg)

Step 2: UART Settings

Mode: **Asynchronous**

Baud Rate: **9600 Bits/s**

Word Length: **8 Bits (including Parity)**

Parity: **None**

Stop Bits: **1**

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-03.jpg)

Step 3: Project Properties

Project -> Properties

C/C++ Build -> Settings -> MCU/MPU GCC Compiler -> Optimization

Optimization Level: **None (-O0)**

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-04.jpg)

C/C++ Build -> Settings -> MCU/MPU GCC Compiler -> Debugging

Debug Level: **Maximun (-g3)**

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-05.jpg)

Step 4: Set the break point

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-06.jpg)

Step 5: Debug Mode

Project -> Build Configurations -> Set Active -> Debug

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-07.jpg)

Step 6: Run debug

Run -> Debug As -> 1 STM32 C/C++ Application

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-08.jpg)

Build Configuration: **Debug**

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-09.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-10.jpg)

Step 7: Check the parameters

When press F8, it will stop at the break point.

Check the parameters, it should display the current value.

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-11.jpg)

There are current values listed in the Variables window.

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-12.jpg)

Press F8 several times, it also display values on the PuTTY terminal.

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-13.jpg)
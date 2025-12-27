## Display Text in Debugging

This project use the **Instrumentation Trace Macrocell (ITM)** to generate trace characters in the debugging mode.

## Process Step

Set PA13, PA14 for Serial Wire Debug (SWD) pins.

![image](https://github.com/yush2106/stm32-labs/blob/main/45-display-characters-in-debugging/img/45-display-characters-in-debugging-01.jpg)

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

Step 4: Debugger settings

Run -> Debug Configurations... -> Debugger

Serial Wire Viewer (SWV): **Enable**

![image](https://github.com/yush2106/stm32-labs/blob/main/45-display-characters-in-debugging/img/45-display-characters-in-debugging-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/45-display-characters-in-debugging/img/45-display-characters-in-debugging-03.jpg)


Step 5: Set the break points

![image](https://github.com/yush2106/stm32-labs/blob/main/45-display-characters-in-debugging/img/45-display-characters-in-debugging-04.jpg)

Step 6: Run debug

Run -> Debug As -> 1 STM32 C/C++ Application

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-08.jpg)

Build Configuration: **Debug**

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-09.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/43-simple-debug-settings/img/43-simple-debug-settings-10.jpg)

Step 7: Show SWM ITM Data Console

Window -> Show View -> SWV -> SWV ITM Data Console

![image](https://github.com/yush2106/stm32-labs/blob/main/45-display-characters-in-debugging/img/45-display-characters-in-debugging-05.jpg)

Step 8: Configure trace

![image](https://github.com/yush2106/stm32-labs/blob/main/45-display-characters-in-debugging/img/45-display-characters-in-debugging-06.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/45-display-characters-in-debugging/img/45-display-characters-in-debugging-07.jpg)

Step 9: Start Trace

Click to start tracing.

When press F8 several times, display characters in the window.

![image](https://github.com/yush2106/stm32-labs/blob/main/45-display-characters-in-debugging/img/45-display-characters-in-debugging-08.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/45-display-characters-in-debugging/img/45-display-characters-in-debugging-09.jpg)
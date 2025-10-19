## Up Counter on LCD

NUCLEO L476RG conntects pin4 to pin9 (PC4 to PC9) with the 1602A LCD. Then, it increase counter number and display it in every second.

## Process step

Step 1: Set PC4 to PC9 for GPIO output.

![image](https://github.com/yush2106/stm32-labs/blob/main/19-display-lcd-text/img/19-display-lcd-text-01.jpg)

Step 2: Connect pins, PC4 to PC7, with 1602A LCD pins, D4 to D7. The power 3.3V and GND connect to VCC and GND of LCD.

![image](https://github.com/yush2106/stm32-labs/blob/main/19-display-lcd-text/img/19-display-lcd-text-02.jpg)

Step 3: Complete LCD initialization.

Step 4: Move to line 2 of LCD.

Step 5: Write counter number into register in every second.

![image](https://github.com/yush2106/stm32-labs/blob/main/20-lcd-up-counter/img/20-lcd-up-counter-01.jpg)
## Transmit text by UART

In this project, NUCLEO-L476RG connects to computer by USB cable which is the UART connection.
Set PA2, PA3 pins for UART connection and NUCLEO-L476RG transmits text by UART.

## Process Step

Step 1: Set PA2 for UART TX and PA3 for UART RX.

![image](https://github.com/yush2106/stm32-labs/blob/main/33-uart-transmit-text/img/33-uart-transmit-text-01.jpg)

Step 2: UART settings.

Mode: **Asynchronous**

Baud Rate: **9600 Bits/s**

Word Length: **8 Bits (including Parity)**

Parity: **None**

Stop Bits: **1**

![image](https://github.com/yush2106/stm32-labs/blob/main/33-uart-transmit-text/img/33-uart-transmit-text-02.jpg)

Step 3: PuTTY settings.

![image](https://github.com/yush2106/stm32-labs/blob/main/33-uart-transmit-text/img/33-uart-transmit-text-03.jpg)

Step 4: Transmit text and display text on PuTTY terminal.

![image](https://github.com/yush2106/stm32-labs/blob/main/33-uart-transmit-text/img/33-uart-transmit-text-04.jpg)
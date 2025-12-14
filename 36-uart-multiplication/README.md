## Multiplication practice by UART connection

Generate 2 integer value, then calculate their multiplication.

When user inputs the answer, display the checking result by UART connection.

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

Step 4: Generate 2 integer values and calculate their multiplication. When user inputs answer, check the answer.

![image](https://github.com/yush2106/stm32-labs/blob/main/36-uart-multiplication/img/36-uart-multiplication-01.jpg)
## Create times table by UART connection

When user input a number, generate a times table and display text by UART connection.

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

Step 4: User input a number.

![image](https://github.com/yush2106/stm32-labs/blob/main/35-uart-times-table/img/35-uart-times-table-01.jpg)

Step 5: Generate the times table.

![image](https://github.com/yush2106/stm32-labs/blob/main/35-uart-times-table/img/35-uart-times-table-02.jpg)
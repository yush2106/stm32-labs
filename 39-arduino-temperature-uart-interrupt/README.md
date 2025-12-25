## Use interrupt UART to connect to Arduino and receive temperature

Use interrupt UART connection to receive temperature value when Arduino transmits.

## Process Step

Step 1: Set PA2 to USART2_TX, PA3 to USART2_RX, PA0 to UART4_TX, and PA1 to UART4_RX.

![image](https://github.com/yush2106/stm32-labs/blob/main/38-arduino-temperature-uart/img/38-arduino-temperature-uart-01.jpg)

Step 2: USART2 and UART4 settings.

![image](https://github.com/yush2106/stm32-labs/blob/main/33-uart-transmit-text/img/33-uart-transmit-text-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/38-arduino-temperature-uart/img/38-arduino-temperature-uart-02.jpg)

Step 3: Arduino UNO connects to NUCLEO-L476RG, it retrieves the TMP36 temperature and sends values by UART connection. Arduino A0, 3.3V, and GND connect to TMP36 sensor. NUCLEO-L476RG PA1 connects to Arduino D7 pin.

![image](https://github.com/yush2106/stm32-labs/blob/main/38-arduino-temperature-uart/img/38-arduino-temperature-uart-03.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/38-arduino-temperature-uart/img/38-arduino-temperature-uart-04.jpg)

It should restart the **HAL_UART_Receive_IT()** function while executing the UART interrupt callbak.

![image](https://github.com/yush2106/stm32-labs/blob/main/39-arduino-temperature-uart-interrupt/img/39-arduino-temperature-uart-interrupt-01.jpg)

Display Arduino temperature on PuTTY terminal.

![image](https://github.com/yush2106/stm32-labs/blob/main/38-arduino-temperature-uart/img/38-arduino-temperature-uart-05.jpg)
## Display DMA temperature by UART connection

In this project, DMA retrieves the temperature sensor (TMP36) value, then display temperature by UART connection.

## Process Step

Step 1: Set PC0 for ADC1_IN1, PA2 for USART_TX, and PA3 for USART_RX.

![image](https://github.com/yush2106/stm32-labs/blob/main/37-display-dma-temperature-by-uart/img/37-display-dma-temperature-by-uart-01.jpg)

Step 2: Clock settings.

Set the ADC clock for 32Mhz.

![image](https://github.com/yush2106/stm32-labs/blob/main/37-display-dma-temperature-by-uart/img/37-display-dma-temperature-by-uart-02.jpg)

Step 3: DMA settings for ADC.

Set the DMA1 for ADC1.

![image](https://github.com/yush2106/stm32-labs/blob/main/37-display-dma-temperature-by-uart/img/37-display-dma-temperature-by-uart-03.jpg)

In NVIC settings, enable the DMA1 channel1 global interrupt.

![image](https://github.com/yush2106/stm32-labs/blob/main/37-display-dma-temperature-by-uart/img/37-display-dma-temperature-by-uart-04.jpg)

Step 4: ADC1 Parameter Settings.

Resolution: **ADC 12-bit resolution**

Scan Conversioin Mode: **Disabled**

Continuous Conversion Mode: **Enabled**

DMA Continuous Requests: **Enabled**

End of Conversion Selection: **End of single conversion**

Overrun behaviour: **Overrun data overwritten**

![image](https://github.com/yush2106/stm32-labs/blob/main/37-display-dma-temperature-by-uart/img/37-display-dma-temperature-by-uart-05.jpg)

Number Of Conversion: **1**

Channel: **Channel 1**

![image](https://github.com/yush2106/stm32-labs/blob/main/37-display-dma-temperature-by-uart/img/37-display-dma-temperature-by-uart-06.jpg)

Step 5: Set PA2 for UART TX and PA3 for UART RX.

![image](https://github.com/yush2106/stm32-labs/blob/main/33-uart-transmit-text/img/33-uart-transmit-text-01.jpg)

Step 6: UART settings.

Mode: **Asynchronous**

Baud Rate: **9600 Bits/s**

Word Length: **8 Bits (including Parity)**

Parity: **None**

Stop Bits: **1**

![image](https://github.com/yush2106/stm32-labs/blob/main/33-uart-transmit-text/img/33-uart-transmit-text-02.jpg)

Step 7: PuTTY settings.

![image](https://github.com/yush2106/stm32-labs/blob/main/33-uart-transmit-text/img/33-uart-transmit-text-03.jpg)

Board wiring.

![image](https://github.com/yush2106/stm32-labs/blob/main/37-display-dma-temperature-by-uart/img/37-display-dma-temperature-by-uart-07.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/37-display-dma-temperature-by-uart/img/37-display-dma-temperature-by-uart-08.jpg)

Display temperature value on UART terminal.

![image](https://github.com/yush2106/stm32-labs/blob/main/37-display-dma-temperature-by-uart/img/37-display-dma-temperature-by-uart-09.jpg)
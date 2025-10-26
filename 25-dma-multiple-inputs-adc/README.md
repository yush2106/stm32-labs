## DMA mode multiple inputs for ADC

DMA mode could read the multiple channel data and store the data in memory without CPU intervention.

When DMA interrupt signal inputs, retrieve values from memory and display on the LCD.

## Process Step

Step 1: Set PC0, PC1 for ADC1 input, and set PC4 to PC9 for LCD pins.

![image](https://github.com/yush2106/stm32-labs/blob/main/22-multiple-inputs-adc/img/22-multiple-inputs-adc-01.jpg)

Step 2: ADC1 settings.

Channel 1: **IN1 Single-ended**

Channel 2: **IN2 Single-ended**

Resolution: **ADC 12-bit resolution**

Scan Conversion Mode: **Enabled**

Continuous Conversion Mode: **Enabled**

DMA Continuous Requests: **Enabled**

End Of Conversion Selection: **End of sequence of conversion**

Overrun behaviour: **Overrun data overwritten**

![image](https://github.com/yush2106/stm32-labs/blob/main/25-dma-multiple-inputs-adc/img/25-dma-multiple-inputs-adc-01.jpg)

Number Of Conversion: **2**

Rank 1: **Channel 1**

Rank 2: **Channel 2**

![image](https://github.com/yush2106/stm32-labs/blob/main/22-multiple-inputs-adc/img/22-multiple-inputs-adc-03.jpg)

Set **DMA Channel 1** for DMA Settings.

Set **Normal** mode for DMA Request Settings.

![image](https://github.com/yush2106/stm32-labs/blob/main/25-dma-multiple-inputs-adc/img/25-dma-multiple-inputs-adc-02.jpg)

Set DMA1 channel 1 global interrupt **Enabled**.

![image](https://github.com/yush2106/stm32-labs/blob/main/25-dma-multiple-inputs-adc/img/25-dma-multiple-inputs-adc-03.jpg)

Step 3: Clock settings. Set the ADC timing.

![image](https://github.com/yush2106/stm32-labs/blob/main/23-interrupt-input-adc/img/23-interrupt-input-adc-03.jpg)

Step 4: While knobing the two potentiometers, the real-time volt values are displayed on the LCD.

The analog values of the potentiometers are retireved by DMA mode.

![image](https://github.com/yush2106/stm32-labs/blob/main/22-multiple-inputs-adc/img/22-multiple-inputs-adc-04.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/22-multiple-inputs-adc/img/22-multiple-inputs-adc-05.jpg)
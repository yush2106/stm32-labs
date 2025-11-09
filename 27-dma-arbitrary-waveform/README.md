## DMA Arbitrary Waveform Generator

In this project, generate trapezoidal wavefrom with DMA mode.

Connect NUCLEO-L476RG PA4 pin and Arduino UNO A0 pin.

## Process Step

Step 1: Set PA4 pin for DAC output.

![image](https://github.com/yush2106/stm32-labs/blob/main/26-sawtooth-waveform-generator/img/26-sawtooth-waveform-generator-01.jpg)

Step 2: APB1 bus clock settings for DAC.

![image](https://github.com/yush2106/stm32-labs/blob/main/26-sawtooth-waveform-generator/img/26-sawtooth-waveform-generator-04.jpg)

Step 3: Timer settings.

![image](https://github.com/yush2106/stm32-labs/blob/main/27-dma-arbitrary-waveform/img/27-dma-arbitrary-waveform-01.jpg)

Step 4: DAC settings.

![image](https://github.com/yush2106/stm32-labs/blob/main/27-dma-arbitrary-waveform/img/27-dma-arbitrary-waveform-02.jpg)

Step 5: DMA settings for DAC.

![image](https://github.com/yush2106/stm32-labs/blob/main/27-dma-arbitrary-waveform/img/27-dma-arbitrary-waveform-03.jpg)

Step 6: NVIC settings for DMA.

![image](https://github.com/yush2106/stm32-labs/blob/main/27-dma-arbitrary-waveform/img/27-dma-arbitrary-waveform-04.jpg)

Step 7: Generate digital values and convert to analog signal values.

![image](https://github.com/yush2106/stm32-labs/blob/main/26-sawtooth-waveform-generator/img/26-sawtooth-waveform-generator-06.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/27-dma-arbitrary-waveform/img/27-dma-arbitrary-waveform-05.jpg)
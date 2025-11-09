## Sawtooth Wave Generator

In this project, generate digital signal and use DAC pin to output analog signal.

Set PA4 for DAC output and TIM2 for drigger timer.

Install [ZaidaScope](https://github.com/ZaidaTek/ZaiDAQ/releasesUse) on Arduino UNO which received analog signal from NUCLEO-L476RG.

## Process Step

Step 1: Set PA4 pin for DAC output.

![image](https://github.com/yush2106/stm32-labs/blob/main/26-sawtooth-waveform-generator/img/26-sawtooth-waveform-generator-01.jpg)

Step 2: TIM2 of timer settings and interrupt settings.

![image](https://github.com/yush2106/stm32-labs/blob/main/26-sawtooth-waveform-generator/img/26-sawtooth-waveform-generator-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/26-sawtooth-waveform-generator/img/26-sawtooth-waveform-generator-03.jpg)

Step 3: APB1 bus clock settings for DAC.

![image](https://github.com/yush2106/stm32-labs/blob/main/26-sawtooth-waveform-generator/img/26-sawtooth-waveform-generator-04.jpg)

Step 4: DAC1 settings.

![image](https://github.com/yush2106/stm32-labs/blob/main/26-sawtooth-waveform-generator/img/26-sawtooth-waveform-generator-05.jpg)

Step 5: Connect NUCLEO-L476RG PA4 pin, GND pin and Arduino UNO A0 pin, GND pin.

Seperate 10 steps to output analog signal.

![image](https://github.com/yush2106/stm32-labs/blob/main/26-sawtooth-waveform-generator/img/26-sawtooth-waveform-generator-06.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/26-sawtooth-waveform-generator/img/26-sawtooth-waveform-generator-07.jpg)

## Hardware Triangular Waveform Generation

In this project, use the built function of NUCLEO-L476RG to generate triangular waveform.

Connect NUCLEO-L476RG PA4 pin and GND pin with Arduino UNO A0 pin and GND pin.

## Process Step

Step 1: Set PA4 pin for DAC output.

![image](https://github.com/yush2106/stm32-labs/blob/main/26-sawtooth-waveform-generator/img/26-sawtooth-waveform-generator-01.jpg)

Step 2: Set APB1 bus clocking for DAC.

![image](https://github.com/yush2106/stm32-labs/blob/main/26-sawtooth-waveform-generator/img/26-sawtooth-waveform-generator-04.jpg)

Step 3: DAC settings.

Wave generation mode: **Triangular wave generation**.

Maximun Triangular Amplitude: **2047**.

2047 / 4095 * 3.3 = 1.65V

![image](https://github.com/yush2106/stm32-labs/blob/main/28-hardware-triangular-waveform/img/28-hardware-triangular-waveform-01.jpg)

Step 4: Timer settings.

![image](https://github.com/yush2106/stm32-labs/blob/main/28-hardware-triangular-waveform/img/28-hardware-triangular-waveform-01.jpg)

Step 5: Connect PA4 pin, GND pin with Arduino UNO A0 pin, GND pin.

![image](https://github.com/yush2106/stm32-labs/blob/main/26-sawtooth-waveform-generator/img/26-sawtooth-waveform-generator-06.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/28-hardware-triangular-waveform/img/28-hardware-triangular-waveform-03.jpg)
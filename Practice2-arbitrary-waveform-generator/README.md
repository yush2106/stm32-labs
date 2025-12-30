## Arbitrary Waveform Generator

In this program, I created sawtooth, square, sine, trapezoidal and triangular waveform 
functions to generate values for DAC. Then, NUCLEO-L476RG outputted the analog signal 
by DMA mode. 
The Arduino Uno received analog signal from NUCLEO-L476RG and integrated ZaidaScope 
to display waveform. 
When I switched waveform type by clicking the onboard button, it changed the real-time 
waveform on ZaidaScope and displayed waveform type text on LCD with switching LEDs.

## Process steps

Step 1: Configure pins

PC13 for onboard button, PA4 for DAC pin, PC4 to PC9 for LCD, and PB0 to PB4 for LED.

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-01.jpg)

Step 2: Onboard button settings

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-02.jpg)

Step 3: DAC settings

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-03.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-04.jpg)

Step 4: Timer settings

Prescaler (PSC - 16 bits value): **399**

Counter Period (AutoReload Register - 32 bits value): **19**

$$I = \frac{(P+1)(A+1)}{f}$$

When P is 399, A is 19, f is 80(Mhz), then I (interval time) is 100us.

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-05.jpg)

Step 5: NVIC settings

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-06.jpg)

Circuits diagram

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-07.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-08.jpg)

Program flowchart

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-09.jpg)

Click the onboard button, switch the wave type.

DAC outputed wavefrom signal on ZaidaScope, then display text on LCD and switch LEDs.

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-10.jpg)
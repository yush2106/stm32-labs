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

GPIO mode: **External Interrupt Mode with Falling edge trigger detection**

EXTI line[15:10] interrupts: **Enabled**

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-02.jpg)

Step 3: DAC settings

OUT1 connected to: **only to external pin**

Output Buffer: **Enable**

Trigger: **Timer 2 Trigger Out event**

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-03.jpg)

DMA Request Settings

Mode: **Circular**

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-04.jpg)

Step 4: Timer settings

Prescaler (PSC - 16 bits value): **399**

Counter Period (AutoReload Register - 32 bits value): **19**

$$I = \frac{(P+1)(A+1)}{f}$$

When __*P*__ is 399, __*A*__ is 19, __*f*__ is 80(Mhz), then __*I*__ (interval time) is 100us.

auto-reload preload: **Enable**

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-05.jpg)

Step 5: NVIC settings

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-06.jpg)

Circuits diagram

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-07.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-08.jpg)

Program flowchart

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-09.jpg)

Click the onboard button, switch the wave type.

Use DAC to output wavefrom signal to ZaidaScope, then display text on LCD and switch LEDs.

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-10.jpg)
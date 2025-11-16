## Continuous Variable Duty Cycle

In this project, try to switch frequency dynamically.

When it increases or decreases the CCR pulse in each step, it will generate the various output waveform duty cycles.

## Process Step

Step 1: Set PB3 pin for PWM timer channel 2 output.

![image](https://github.com/yush2106/stm32-labs/blob/main/29-pwm-10khz-half-pulsewidth/img/29-pwm-10khz-half-pulsewidth-01.jpg)

Step 2: Timer 2 settings.

Clock Source: **Internal Clock**.

Channel 2: **PWM Generation CH2**.

Prescaler (PSC - 16 bits value): **79**.

Counter Period (AutoReload Register - 32 bits value): **99**.

auto-reload preload: **Enable**.

Mode: **PWM mode 1**.

Pulse (32 bits value): **50**.

![image](https://github.com/yush2106/stm32-labs/blob/main/29-pwm-10khz-half-pulsewidth/img/29-pwm-10khz-half-pulsewidth-02.jpg)

Step 3: Connect NUCLEO-L476RG PB3 pin with Arduino UNO A0 pin, and connect NUCLEO-L476RG GND pin with Arduino UNO GND pin.

![image](https://github.com/yush2106/stm32-labs/blob/main/29-pwm-10khz-half-pulsewidth/img/29-pwm-10khz-half-pulsewidth-03.jpg)

Step 4: Set the different CCR pulse in each step, it generates the various output waveform duty cycles.

![image](https://github.com/yush2106/stm32-labs/blob/main/30-continuous-variable-duty-cycle/img/30-continuous-variable-duty-cycle-01.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/30-continuous-variable-duty-cycle/img/30-continuous-variable-duty-cycle-02.jpg)
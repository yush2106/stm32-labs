## 10kHz Half Pulsewidth

This is a PWM (Pulse Width Modulation) project, try to generate 10kHz half pulsewidth waveform.

Set NUCLEO-L476RG PB3 pin for PWM timer channel 2 output.

It connects to Arduino UNO A0 pin, and displays waveform with the ZaidaScope.

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

This is the interrupt interval time.

$$I = \frac{(P+1)(A+1)}{f}$$

__*I*__: Interrupt interval time

__*P*__: The pre-scaller value

__*A*__: Reload value to the auto-reload register

__*f*__: The clock frequency

Set the PWM frequency.

$$
f_{PWM} = \frac{f}{(P+1)(A+1)} 
= \frac{80 \times 10^6}{(79+1)(99+1)} = 10,000 Hz = 10kHz
$$

Set the CCR (capcure/compare register)

CCR1 is PWM Mode 1.

The ARR (auto-reload register) is (A+1) = (99+1) = 100.

For the half duty cycle, set pulse to 50.

$$
D = \frac{CCR_{pulse}}{ARR} = \frac{50}{100} = 0.5 = 50\%
$$

![image](https://github.com/yush2106/stm32-labs/blob/main/29-pwm-10khz-half-pulsewidth/img/29-pwm-10khz-half-pulsewidth-02.jpg)

Step 3: Connect NUCLEO-L476RG PB3 pin with Arduino UNO A0 pin, and connect NUCLEO-L476RG GND pin with Arduino UNO GND pin.

![image](https://github.com/yush2106/stm32-labs/blob/main/29-pwm-10khz-half-pulsewidth/img/29-pwm-10khz-half-pulsewidth-03.jpg)

Step 4: Display PWM waveform with the ZaidaScope.

![image](https://github.com/yush2106/stm32-labs/blob/main/29-pwm-10khz-half-pulsewidth/img/29-pwm-10khz-half-pulsewidth-04.jpg)
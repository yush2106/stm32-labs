## Multiple PWM Waveforms

It's a project to generate the multiple PWM waveforms.

Set PA15 pin for PWM channel 1, PB3 pin for PWM channel 2, and PB10 pin for PWM channel 3.

The channel 1 is 25% duty cycle, channel 2 is 50% duty cycle, and channel 3 is 75% duty cycle.

## Process Step

Step 1: Set PA15 pin for PWM timer2 channel 1, PB3 pin for  channel 2, and PB10 for channel 3.

![image](https://github.com/yush2106/stm32-labs/blob/main/31-multiple-pwm-wavwforms/img/31-multiple-pwm-wavwforms-01.jpg)

Step 2: Timer 2 settings.

Clock Source: **Internal Clock**.

Channel 1: **PWM Generation CH1**.

Channel 2: **PWM Generation CH2**.

Channel 3: **PWM Generation CH3**.

Prescaler (PSC - 16 bits value): **79**.

Counter Period (AutoReload Register - 32 bits value): **99**.

auto-reload preload: **Enable**.

PWM Generation Channel 1 Mode: **PWM mode 1**.

PWM Generation Channel 2 Mode: **PWM mode 1**.

PWM Generation Channel 3 Mode: **PWM mode 1**.

![image](https://github.com/yush2106/stm32-labs/blob/main/31-multiple-pwm-wavwforms/img/31-multiple-pwm-wavwforms-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/31-multiple-pwm-wavwforms/img/31-multiple-pwm-wavwforms-03.jpg)

Step 3: NUCLEO-L476RG PB3, PA15 and PB10 pins connect to Arduino UNO A0, A1 and A2 pins. The GND pins are connected.

![image](https://github.com/yush2106/stm32-labs/blob/main/31-multiple-pwm-wavwforms/img/31-multiple-pwm-wavwforms-04.jpg)

Step 4: The multiple waveforms are displayed in these following pictures.

Multiple waveforms.

![image](https://github.com/yush2106/stm32-labs/blob/main/31-multiple-pwm-wavwforms/img/31-multiple-pwm-wavwforms-05.jpg)

25% duty cycle.

![image](https://github.com/yush2106/stm32-labs/blob/main/31-multiple-pwm-wavwforms/img/31-multiple-pwm-wavwforms-06.jpg)

50% duty cycle.

![image](https://github.com/yush2106/stm32-labs/blob/main/31-multiple-pwm-wavwforms/img/31-multiple-pwm-wavwforms-07.jpg)

75% duty cycle.

![image](https://github.com/yush2106/stm32-labs/blob/main/31-multiple-pwm-wavwforms/img/31-multiple-pwm-wavwforms-08.jpg)
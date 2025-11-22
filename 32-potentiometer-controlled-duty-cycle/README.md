## Potentiometer Controlled Duty Cycle

Setup the potentiometer which generate the analog signal to control the LED luminance.

Connect PC0 pin for potentiometer ADC input, and connect PA15 pin for the LED.

Convert analog signal value to manipulate the PWM value for the LED brightness.

## Process Step

Step 1: Connect PC0 pin for ADC input, and PA15 for PWM timer.

![image](https://github.com/yush2106/stm32-labs/blob/main/32-potentiometer-controlled-duty-cycle/img/32-potentiometer-controlled-duty-cycle-01.jpg)

Step 2: Timer2 settings.

Clock Source: **Internal Clock**

Channel 1: **PWM Generation CH1**

Prescaler (PSC - 16 bits value): **79**

Counter Period: **999**

auto-reload  preload: **Enable**

![image](https://github.com/yush2106/stm32-labs/blob/main/32-potentiometer-controlled-duty-cycle/img/32-potentiometer-controlled-duty-cycle-02.jpg)

Step 3: ADC1 settings.

IN1: **IN1 Single-ended**

Continuous Conversion Mode: **Enabled**

End of Conversion Selection: **End of single conversion**

Overrun behaviour: **Overrun data overwritten**

![image](https://github.com/yush2106/stm32-labs/blob/main/32-potentiometer-controlled-duty-cycle/img/32-potentiometer-controlled-duty-cycle-03.jpg)

Step 4: Retrieved the ADC value and convert the PWM duty cycle. Then, the LED luminance will be manipulated by the potentiometer.

![image](https://github.com/yush2106/stm32-labs/blob/main/32-potentiometer-controlled-duty-cycle/img/32-potentiometer-controlled-duty-cycle-04.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/32-potentiometer-controlled-duty-cycle/img/32-potentiometer-controlled-duty-cycle-05.jpg)
## Timer interrupt and flash onboard LED

Use the internal timer to generate interrupt signal, then flash the onboard LED.

The internal timer is defined for timer 2 (TIM2), and drives the GPIO output pin 5 (PA5) to flash onboard LED.

## Process steps

Step 1: The internal timer enters to Pre-scaler, it drives the timer counter register, which is auto-reload from the auto-reload register after it counts to 0.

![image](https://github.com/yush2106/stm32-labs/blob/main/17-timer-interrupt-flash-led/img/17-timer-interrupt-flash-led-01.jpg)

When the counter register is auto-reload, generate the timer interrupt signal.

This is the interrupt interval time.

$$I = \frac{(P+1)(A+1)}{f}$$

__*I*__: Interrupt interval time

__*P*__: The pre-scaller value

__*A*__: Reload value to the auto-reload register

__*f*__: The clock frequency

This is the reload value.

$$A = \frac{f × I}{P + 1} - 1$$

The clock frequency of NUCLEO-L476RG is 80Mhz ( $80 ×10^6$). If the interval time is 1 second and pre-scaller is 39999, the reload value is 1999.

$$A = \frac{(80 × 10^6) × 1}{39999 + 1} - 1 = 1999$$

Step 2: Set these parameters for timer 2.

Prescaler value: 39999

Counter Mode: Down

Counter Period(AutoReloaded Register): 1999

Internal Clock Division: Division by 2

auto-reload preload: Enable

TIM2 global interrupt: Enabled

![image](https://github.com/yush2106/stm32-labs/blob/main/17-timer-interrupt-flash-led/img/17-timer-interrupt-flash-led-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/17-timer-interrupt-flash-led/img/17-timer-interrupt-flash-led-03.jpg)

Step 3: Enable TIM2 global interrupt in NVIC settings.

![image](https://github.com/yush2106/stm32-labs/blob/main/17-timer-interrupt-flash-led/img/17-timer-interrupt-flash-led-04.jpg)

Step 4: Define the timer interrupt callback function to toggle onblard LED.

Step 5: Start timer 2 in the main function.

![image](https://github.com/yush2106/stm32-labs/blob/main/01-flash-led/img/01-flash-led.jpg)
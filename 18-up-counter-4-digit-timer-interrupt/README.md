## Up counter for 4 digit 7 segment display with timer interrupts signal

Connect port C pins, PC0 to PC6, for 7 segment displat LEDS. The other pins, PC7 to PC10, control the digit display.

Define timer 2 (TIM2) for increasing display number by 1 second.

Define timer 3 (TIM3) for 4 digit display by 4 micro seconds.

## Process step

Step 1: Set the display number interval time by 1 second.

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

Set these parameters for timer 2.

Prescaler value: 39999

Counter Mode: Down

Counter Period(AutoReloaded Register): 1999

Internal Clock Division: Division by 2

auto-reload preload: Enable

TIM2 global interrupt: Enabled

![image](https://github.com/yush2106/stm32-labs/blob/main/17-timer-interrupt-flash-led/img/17-timer-interrupt-flash-led-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/17-timer-interrupt-flash-led/img/17-timer-interrupt-flash-led-03.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/17-timer-interrupt-flash-led/img/17-timer-interrupt-flash-led-04.jpg)

Step 2: Set the 4 digit diaply time by 4ms.

This is the reload value.

$$A = \frac{(80 × 10^6) × (4 × 10^{-3})}{39999 + 1} - 1 = 7$$

Set these parameters for timer 3.

Prescaler value: 39999

Counter Mode: Down

Counter Period(AutoReloaded Register): 7

Internal Clock Division: Division by 2

auto-reload preload: Enable

TIM3 global interrupt: Enabled

![image](https://github.com/yush2106/stm32-labs/blob/main/18-up-counter-4-digit-timer-interrupt/img/18-up-counter-4-digit-timer-interrupt-01.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/18-up-counter-4-digit-timer-interrupt/img/18-up-counter-4-digit-timer-interrupt-02.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/18-up-counter-4-digit-timer-interrupt/img/18-up-counter-4-digit-timer-interrupt-03.jpg)

Step 3: Define the callback function for increasing display number and enabling 4 digit number of 7 segment display.

Step 4: Increase display number when the timer 2 interrupt signal inputs. If the display number greater than the maximum number, reset the display number to 0.

Step 5: When the timer 3 interrupt signal inputs, display each digit number.

Step 6: Start timer 2 and timer 3 process in the main.c file.

![image](https://github.com/yush2106/stm32-labs/blob/main/15-four-digit-7-segment-display/img/15-four-digit-7-segment-display-03.jpg)
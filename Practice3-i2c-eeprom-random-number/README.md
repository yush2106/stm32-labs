## I<sup>2</sup>C EEPROM Access Random Number

In this practice, I build the project process on the FreeRTOS structure. 
When the onboard button clicked, generate a random number and write the random 
number into the 24LC256 EEPROM. 
Next step, read the stored number from the EEPROM 24LC256, then display number on the 
LCD. Try to display the number as a "news ticker" both on the LCD and 4-digit 7 segment 
display.

## Process steps

Step 1: Configure pins

PC13 for onboard button, PB8 and PB9 for I2C serial clock and serial data, PC4 to PC9 for 
LCD, PC0 to PC3 for BJT 2N2222A, and PB0 to PB6 for 4-digit 7 segment display.

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice3-i2c-eeprom-random-number/img/Practice3-i2c-eeprom-random-number-01.jpg)

Step 2: Onboard button settings

GPIO mode: **External Interrupt Mode with Falling edge trigger detection**

EXTI line[15:10] interrupts: **Enabled**

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice2-arbitrary-waveform-generator/img/Practice2-arbitrary-waveform-generator-02.jpg)

Step 3: Timer2 settings

Set timer2 interrupt clock for 4-digit 7 segment display.

$$I = \frac{(P+1)(A+1)}{f}$$

When __*P*__ is 39999, __*A*__ is 7, __*f*__ is 80(Mhz), then __*I*__ (interval time) is 4ms.

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice3-i2c-eeprom-random-number/img/Practice3-i2c-eeprom-random-number-02.jpg)

Step 4: I<sup>2</sup>C settings

I2C: **I2C**

Custom Timing: **Disabled**

I2C Speed Mode: **Standard Mode**

I2C Speed Frequency (KHz): **100**

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice3-i2c-eeprom-random-number/img/Practice3-i2c-eeprom-random-number-03.jpg)

Step 5: FreeRTOS settings

Interface: **CMSIS_V2**

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice3-i2c-eeprom-random-number/img/Practice3-i2c-eeprom-random-number-04.jpg)

Circuits diagram

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice3-i2c-eeprom-random-number/img/Practice3-i2c-eeprom-random-number-05.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice3-i2c-eeprom-random-number/img/Practice3-i2c-eeprom-random-number-06.jpg)

Program flowchart

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice3-i2c-eeprom-random-number/img/Practice3-i2c-eeprom-random-number-07.jpg)

Click the onboard button to generate a random number, display the number on the LCD and write the number into the 24LC256 EEPROM by I<sup>2</sup>C connection.

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice3-i2c-eeprom-random-number/img/Practice3-i2c-eeprom-random-number-08.jpg)

Read the number from EEPROM and display it on the LCD.

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice3-i2c-eeprom-random-number/img/Practice3-i2c-eeprom-random-number-09.jpg)

Display the number as a "news ticker" both on the LCD and 4-digit 7 segment display.

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice3-i2c-eeprom-random-number/img/Practice3-i2c-eeprom-random-number-10.jpg)
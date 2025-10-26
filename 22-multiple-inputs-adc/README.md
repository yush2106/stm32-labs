## Multiple inputs for ADC

There are 2 potentiometers connect to PC0 and PC1, set to the  ADC1 channel 1 and channel 2.

Cconntects pin4 to pin9 (PC4 to PC9) with the 1602A LCD.

## Process step

Step 1: Configure the PC0 for ADC1_IN1, and PC1 for ADC1_IN2. The PC0 to PC9 are connected for LCD pins.

![image](https://github.com/yush2106/stm32-labs/blob/main/22-multiple-inputs-adc/img/22-multiple-inputs-adc-01.jpg)

Step 2: The following settings are for ADC1.

Resolution: **ADC 12-bit resolution**

Scan Conversion Mode: **Enabled**

Continuous Conversion Mode: **Enabled**

End Of Conversion Selection: **End of single conversion**

Overrun behaviour: **Overrun data overwritten**

![image](https://github.com/yush2106/stm32-labs/blob/main/22-multiple-inputs-adc/img/22-multiple-inputs-adc-02.jpg)

Step 3: The following settings are for ADC1_IN1 and ADC_IN2.

Number of Conversion: **2**

**Rank 1:**

Channel: **Channel 1**

Sampling: **2.5 Cycles**

Offset Number: **No offset**

**Rank 2:**

Channel: **Channel 2**

Sampling: **2.5 Cycles**

Offset Number: **No offset**

![image](https://github.com/yush2106/stm32-labs/blob/main/22-multiple-inputs-adc/img/22-multiple-inputs-adc-03.jpg)

Step 4: Start ADC1, then poll and conversion. Retrieve the channel 1 and channel 2 values of ADC1, then convert 12-bit resolution values and display on the LCD.

While knobing the two potentiometers, the real-time volt values are displayed on the LCD.

![image](https://github.com/yush2106/stm32-labs/blob/main/22-multiple-inputs-adc/img/22-multiple-inputs-adc-04.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/22-multiple-inputs-adc/img/22-multiple-inputs-adc-05.jpg)
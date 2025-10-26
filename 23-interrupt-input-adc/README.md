## ADC with interrupt input

In this project, detect the ADC interrupt signal, and diplay the retrieved analog value on the LCD.

Set PC0 for ADC1 channel 1 input, then enabled the interrupt mode in NVIC settings.

The interrupt signal drives to get the analog value.

## Process step

Step 1: Set PC0 for **ADC1_IN1**. Set PC4 to PC9 for LCD pins.

![image](https://github.com/yush2106/stm32-labs/blob/main/21-adc-analog-voltmeter/img/21-adc-analog-voltmeter-01.jpg)

Step 2: In ADC1, set **IN1 Single-ended** for channel 1.

Resolution: **ADC 12-bit resolution**

Scan Conversion Mode: **Disabled**

Continuous Conversion Mode: **Disabled**

End Of Conversion Selection: **End of single conversion**

Overrun behaviour: **Overrun data overwritten**

![image](https://github.com/yush2106/stm32-labs/blob/main/23-interrupt-input-adc/img/23-interrupt-input-adc-01.jpg)

Set the ADC1 interrupts **Enabled** in the NVIC settings.

![image](https://github.com/yush2106/stm32-labs/blob/main/23-interrupt-input-adc/img/23-interrupt-input-adc-02.jpg)

Step 3: Clock settings. Set the ADC timing.

![image](https://github.com/yush2106/stm32-labs/blob/main/23-interrupt-input-adc/img/23-interrupt-input-adc-03.jpg)

Step 4: When ADC interrupts, get analog value and convert 12-bit value of the potentiometer. Display the voltage value on the LCD.

![image](https://github.com/yush2106/stm32-labs/blob/main/21-adc-analog-voltmeter/img/21-adc-analog-voltmeter-03.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/21-adc-analog-voltmeter/img/21-adc-analog-voltmeter-05.jpg)
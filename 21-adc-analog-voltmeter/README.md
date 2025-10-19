## Analog Voltmeter

NUCLEO L476RG conntects pin4 to pin9 (PC4 to PC9) with the 1602A LCD.

The potentiometer connects to PC0, it use the ADC input channel 1.

## Process step

Step 1: Set PC4 to PC9 for GPIO output, and PC0 for ADC input channel 1. 

![image](https://github.com/yush2106/stm32-labs/blob/main/21-adc-analog-voltmeter/img/21-adc-analog-voltmeter-01.jpg)

Step 2: Set channel 1 of ADC 1 is **IN1 Single-ended**.

Resolution is **ADC 12-bit resolution**.

Continious Conversion Mode is **Enabled**.

End of Conversion Selection is **End of sequence of conversion**.

Overrun behaviour is **Overrun data overwritten**.

![image](https://github.com/yush2106/stm32-labs/blob/main/21-adc-analog-voltmeter/img/21-adc-analog-voltmeter-02.jpg)

Step 3: The potentiometer connects to PC0, PC4 to PC9 connect to D4 to D7, E and RS of LCD.

![image](https://github.com/yush2106/stm32-labs/blob/main/21-adc-analog-voltmeter/img/21-adc-analog-voltmeter-03.jpg)

Step 4: Set the project **Properties**. To enable the 
**sprintf** function for converting float format values.

![image](https://github.com/yush2106/stm32-labs/blob/main/21-adc-analog-voltmeter/img/21-adc-analog-voltmeter-04.jpg)

Step 5: Start ADC1, then poll and conversion. Convert ADC value to 12-bit resolution value and display on the LCD.

It's the real-time volt value on the LCD while knobing the potentiometer.

![image](https://github.com/yush2106/stm32-labs/blob/main/21-adc-analog-voltmeter/img/21-adc-analog-voltmeter-05.jpg)
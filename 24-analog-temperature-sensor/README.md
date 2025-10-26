## Analog Temperature Sensor
In this lab, use the temperature sensor (TMP36) that connects to pins PC0 of NUCLEO-L476RG.

Set PC0 for Channel 1 of ADC1 and connect pins, PC4 to PC9, for LCD.

Convert 12-bit ADC value and calculate temperature value, then display on LCD.

## Process Step

Step 1: Set PC0 to ADC1_IN1, and PC4 to PC9 to GPIO_Output.

![image](https://github.com/yush2106/stm32-labs/blob/main/24-analog-temperature-sensor/img/24-analog-temperature-sensor-01.jpg)

Step 2: The settings of ADC1 are listed in the following list.

IN1: **IN1 Single-ended**

Resolution: **ADC 12-bit resolution**

Continuous Conversion Mode: **Disabled**

End of Conversion Selection: **End of single conversion**

Overrun behaviour: **Overrun data overwritten**

![image](https://github.com/yush2106/stm32-labs/blob/main/24-analog-temperature-sensor/img/24-analog-temperature-sensor-02.jpg)

Step 3: Set the clock timing for ADC.

![image](https://github.com/yush2106/stm32-labs/blob/main/24-analog-temperature-sensor/img/24-analog-temperature-sensor-03.jpg)

Step 4: Use the temperature sensor (TMP36) for measuring temperature value. It should be calculated and given by:

Temperature = (Voltage - 500) / 10

For example, if the voltage value is 700mv, the temperature is 20°C.

![image](https://github.com/yush2106/stm32-labs/blob/main/24-analog-temperature-sensor/img/24-analog-temperature-sensor-04.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/24-analog-temperature-sensor/img/24-analog-temperature-sensor-05.jpg)
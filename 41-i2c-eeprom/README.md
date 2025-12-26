## I<sup>2</sup>C EEPROM memory

Click the onboard button to generate a number, the value range is from 1 to 9.

Write the number to 24LC256 EEPROM memory by I<sup>2</sup>C cpnnection.

Then, read the number from 24LC256 EEPROM memory and flash the onboard LED for number count times.

## Process Step

Step 1: Set onboard button PC13 is GPIO_EXIT13,  PB8 is **I2C1_SCL** for I<sup>2</sup>C clock line and PB9 is **I2C1_SDA** for I<sup>2</sup>C data line, PA2 is USART2_TX, PA3 is USART2_RX, and onboard LED PA5 is GPIO_Output.

![image](https://github.com/yush2106/stm32-labs/blob/main/41-i2c-eeprom/img/41-i2c-eeprom-01.jpg)

Step 2: Onboard button PC13 interrupt mode

Enable the interrupt mode.

![image](https://github.com/yush2106/stm32-labs/blob/main/41-i2c-eeprom/img/41-i2c-eeprom-02.jpg)

Set GPIO mode is **External Interrput Mode with Falling edge trigger detection**

![image](https://github.com/yush2106/stm32-labs/blob/main/41-i2c-eeprom/img/41-i2c-eeprom-03.jpg)

Step 3: I<sup>2</sup>C settings

I2C: **I2C**

Custom Timing: **Disabled**

I2C Speed Mode: **Standard Mode**

I2C Speed Frequency (KHz): **100**

Rise Time (ns): **0**

Fall Time (ns): **0**

Coefficient of Digital Filter: **0**

![image](https://github.com/yush2106/stm32-labs/blob/main/40-i2c-port-expander/img/40-i2c-port-expander-02.jpg)

Step 4: UART settings

Mode: **Asynchronous**

Baud Rate: **9600 Bits/s**

Word Length: **8 Bits (including Parity)**

Parity: **None**

Stop Bits: **1**

![image](https://github.com/yush2106/stm32-labs/blob/main/33-uart-transmit-text/img/33-uart-transmit-text-02.jpg)

Step 5: Write Command

Refer to the [24LC256 datasheet](https://www.microchip.com/en-us/product/24lc256) for detailed specifications.

![image](https://github.com/yush2106/stm32-labs/blob/main/41-i2c-eeprom/img/41-i2c-eeprom-04.jpg)

When Control Code is **1010**, A2 is **0**, A1 is **0**, A0 is **0**, and RW bit is **0** for write, combine Control Code, A2, A1, A0 and RW bit, then the I2C address byte data is **0xA0**.

<table style="text-align:center; border: 1px solid;">
  <thead style="border: 1px solid;">
    <tr>
      <td style="border: 1px solid;">Start</td>
      <td style="border: 1px solid;" colspan=4>Control Code</td>
      <td style="border: 1px solid;" colspan=3>Chip Select Bits</td>
      <td style="border: 1px solid;">R/W</td>
      <td style="border: 1px solid;">ACK</td>
      <td style="border: 1px solid;" colspan=2>Address High Byte</td>
      <td style="border: 1px solid;">ACK</td>
      <td style="border: 1px solid;">Address Low Byte</td>
      <td style="border: 1px solid;">ACK</td>
      <td style="border: 1px solid;">Data</td>
      <td style="border: 1px solid;">ACK</td>
      <td style="border: 1px solid;">Stop</td>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="border: 1px solid;">S</td>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">A2<br/>pin3</td>
      <td style="border: 1px solid;">A1<br/>pin2</td>
      <td style="border: 1px solid;">A0<br/>pin1</td>
      <td style="border: 1px solid;">0 for Write</td>
      <td style="border: 1px solid;">A</td>
      <td style="border: 1px solid;">X for don't care bit</td>
      <td style="border: 1px solid;">7 bits for High Byte</td>
      <td style="border: 1px solid;">A</td>
      <td style="border: 1px solid;">8 bits for Low Byte</td>
      <td style="border: 1px solid;">A</td>
      <td style="border: 1px solid;">Data Bytes</td>
      <td style="border: 1px solid;">A</td>
      <td style="border: 1px solid;">P</td>
    </tr>
  </tbody>
</table>

Step 6: Read Command

Send the write command including memory address first.

Then, send the read command for reading data from the EEPROM.

<table style="text-align:center; border: 1px solid;">
  <thead style="border: 1px solid;">
    <tr>
      <td style="border: 1px solid;">Start</td>
      <td style="border: 1px solid;" colspan=4>Control Code</td>
      <td style="border: 1px solid;" colspan=3>Chip Select Bits</td>
      <td style="border: 1px solid;">R/W</td>
      <td style="border: 1px solid;">ACK</td>
      <td style="border: 1px solid;" colspan=2>Address High Byte</td>
      <td style="border: 1px solid;">ACK</td>
      <td style="border: 1px solid;">Address Low Byte</td>
      <td style="border: 1px solid;">ACK</td>
      <td style="border: 1px solid;">Start</td>
      <td style="border: 1px solid;" colspan=4>Control Code</td>
      <td style="border: 1px solid;" colspan=3>Chip Select Bits</td>
      <td style="border: 1px solid;">R/W</td>
      <td style="border: 1px solid;">ACK</td>
      <td style="border: 1px solid;">Data</td>
      <td style="border: 1px solid;">NO ACK</td>
      <td style="border: 1px solid;">Stop</td>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="border: 1px solid;">S</td>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">A2<br/>pin3</td>
      <td style="border: 1px solid;">A1<br/>pin2</td>
      <td style="border: 1px solid;">A0<br/>pin1</td>
      <td style="border: 1px solid;">0 for Write</td>
      <td style="border: 1px solid;">A</td>
      <td style="border: 1px solid;">X for don't care bit</td>
      <td style="border: 1px solid;">7 bits for High Byte</td>
      <td style="border: 1px solid;">A</td>
      <td style="border: 1px solid;">8 bits for Low Byte</td>
      <td style="border: 1px solid;">A</td>
      <td style="border: 1px solid;">S</td>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">A2<br/>pin3</td>
      <td style="border: 1px solid;">A1<br/>pin2</td>
      <td style="border: 1px solid;">A0<br/>pin1</td>
      <td style="border: 1px solid;">1 for Read</td>
      <td style="border: 1px solid;">A</td>
      <td style="border: 1px solid;">Data Bytes</td>
      <td style="border: 1px solid;">NA</td>
      <td style="border: 1px solid;">P</td>
    </tr>
  </tbody>
</table>

Step 7: Wiring Diagram

![image](https://github.com/yush2106/stm32-labs/blob/main/41-i2c-eeprom/img/41-i2c-eeprom-05.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/41-i2c-eeprom/img/41-i2c-eeprom-06.jpg)

Click the onboard button to generate a random number and write the number into the 24LC256 EEPROM by I<sup>2</sup>C connection, then read the number from EEPROM and display it on PuTTY terminal, flash the onboard LED for the number count times.

![image](https://github.com/yush2106/stm32-labs/blob/main/41-i2c-eeprom/img/41-i2c-eeprom-07.jpg)
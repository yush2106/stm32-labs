## I<sup>2</sup>C port expander

This project builds the port expander with MCP23017 which is I<sup>2</sup>C interface.

NUCLEO-L476RG sends signals to MCP23017 to turn on or turn off the LED.

## Process Step

Step 1: Set NUCLEO-L476RG PB8 is **I2C1_SCL** for I<sup>2</sup>C clock line and PB9 is **I2C1_SDA** for I<sup>2</sup>C data line.

![image](https://github.com/yush2106/stm32-labs/blob/main/40-i2c-port-expander/img/40-i2c-port-expander-01.jpg)

Step 2: I<sup>2</sup>C settings

I2C: **I2C**

Custom Timing: **Disabled**

I2C Speed Mode: **Standard Mode**

I2C Speed Frequency (KHz): **100**

Rise Time (ns): **0**

Fall Time (ns): **0**

Coefficient of Digital Filter: **0**

![image](https://github.com/yush2106/stm32-labs/blob/main/40-i2c-port-expander/img/40-i2c-port-expander-02.jpg)

Step 3: I<sup>2</sup>C write command

Refer to the [MCP23017 datasheet](https://www.microchip.com/en-us/product/mcp23017) for detailed specifications.

![image](https://github.com/yush2106/stm32-labs/blob/main/40-i2c-port-expander/img/40-i2c-port-expander-03.jpg)

I<sup>2</sup>C Device Address

<table style="text-align:center; border: 1px solid;">
  <thead style="border: 1px solid;">
    <tr>
      <td style="border: 1px solid;">A2 (pin17)</td>
      <td style="border: 1px solid;">A1 (pin16)</td>
      <td style="border: 1px solid;">A0 (pin15)</td>
      <td style="border: 1px solid;">Address</td>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">0x20</td>
    </tr>
    <tr>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">0x21</td>
    </tr>
    <tr>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">0x22</td>
    </tr>
    <tr>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">0x23</td>
    </tr>
    <tr>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">0x24</td>
    </tr>
    <tr>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">0x25</td>
    </tr>
    <tr>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">0x26</td>
    </tr>
    <tr>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">1</td>
      <td style="border: 1px solid;">0x27</td>
    </tr>
  </tbody>
</table>

Register Address is listed in the [MCP23017 datasheet](https://www.microchip.com/en-us/product/mcp23017)

It's 16-bit mode when IOCON.BANK value is **1**, another status, 8-bit mode when IOCON.BANK value is **0**.

The IOCON.BANK value shuold be **0** for 8-bit mode on power-up.

![image](https://github.com/yush2106/stm32-labs/blob/main/40-i2c-port-expander/img/40-i2c-port-expander-04.jpg)

Write command

<table style="text-align:center; border: 1px solid;">
  <thead style="border: 1px solid;">
    <tr>
      <td>Start</td>
      <td colspan=7 style="border: 1px solid;">Device Address (7 bits)</td>
      <td style="border: 1px solid;">R/W</td>
      <td style="border: 1px solid;">ACK</td>
      <td colspan=8 style="border: 1px solid;">Register Address (8 bits)</td>
      <td style="border: 1px solid;">ACK</td>
      <td colspan=8 style="border: 1px solid;">Data (8 bits)</td>
      <td style="border: 1px solid;">ACK</td>
      <td>Stop</td>
    </tr>
  </thead>
  <tbody>
    <tr style="border: 1px solid;">
      <td style="border: 1px solid;">S</td>
      <td>A6</br>0</td>
      <td>A5</br>1</td>
      <td>A4</br>0</td>
      <td>A3</br>0</td>
      <td>A2</br>0</td>
      <td>A1</br>0</td>
      <td>A0</br>0</td>
      <td style="border: 1px solid;">0</td>
      <td style="border: 1px solid;">A</td>
      <td>C7</br>0</td>
      <td>C6</br>0</td>
      <td>C5</br>0</td>
      <td>C4</br>0</td>
      <td>C3</br>0</td>
      <td>C2</br>0</td>
      <td>C1</br>0</td>
      <td>C0</br>0</td>
      <td style="border: 1px solid;">A</td>
      <td>D7</td>
      <td>D6</td>
      <td>D5</td>
      <td>D4</td>
      <td>D3</td>
      <td>D2</td>
      <td>D1</td>
      <td>D0</td>
      <td style="border: 1px solid;">A</td>
      <td style="border: 1px solid;">P</td>
    </tr>
    <tr>
      <td></td>
      <td colspan=8 style="border: 1px solid;">
        Configure MCP23017 A0 (pin15) = 0, A1 (pin16) = 0, A2 (pin17) = 0,</br>
        I<sup>2</sup>C Device Address 0x20 for 7 bits.<br/>
        Conbine R/W value 0 for write mode, then 0x40 for 8 bits
      </td>
      <td></td>
      <td colspan=8 style="border: 1px solid;">
        8-bit mode, IOCON.BANK = 0<br/>
        Write to IODIRA address 0x00</br>
        Write to GPIOA address 0x12
      </td>
      <td></td>
      <td colspan=8 style="border: 1px solid;">
        Set IODIRA data 0xFE, "0b1111_1110",<br/>
        1 for input, 0 for output<br/>
        Set GPIOA data 0x01, then GPA0 is On,<br/>
        Set GPIOA data 0x00, then GPA0 is Off.
      </td>
      <td style="border: 1px solid;"></td>
      <td style="border: 1px solid;"></td>
    </tr>
  </tbody>
</table>

Step 4: Wiring Diagram

![image](https://github.com/yush2106/stm32-labs/blob/main/40-i2c-port-expander/img/40-i2c-port-expander-05.jpg)

Write command to MCP23017 and drive it to turn on or turn off LED.

![image](https://github.com/yush2106/stm32-labs/blob/main/40-i2c-port-expander/img/40-i2c-port-expander-06.jpg)
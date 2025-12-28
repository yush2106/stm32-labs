## Hexadecimal Counter for 7 segment display

Try to display hexadecimal number, 0 to F, for the 7 segment display.

Connect the GPIO port B pins, PB0 to PB6, to the 7 segment display.

## Process steps

Step 1: Define a counter number for the counting hex number.

Step 2: Reset all of the GPIO port B register data.

Step 3: Mapping the register hex number for each counter number.

Step 4: Write hex data into register.

Step 5: Delay.

Step 6: Set the counter number to 0 when it greater than 15.

GPIO port B pins.

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice1-hex-counter-for-7-segment-display/img/Practice1-hex-counter-for-7-segment-display-01.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice1-hex-counter-for-7-segment-display/img/Practice1-hex-counter-for-7-segment-display-02.jpg)

7 segment display circuits.

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice1-hex-counter-for-7-segment-display/img/Practice1-hex-counter-for-7-segment-display-03.jpg)

| NUCLEO-L476RG | 7 segment display LEDs | 7 segment display pins |
| --- | --- | --- |
| PB0 | A | 7 |
| PB1 | B | 6 |
| PB2 | C | 4 |
| PB3 | D | 2 |
| PB4 | E | 1 |
| PB5 | F | 9 |
| PB6 | G | 10 |
| GND | common cathode | 3 and 8 |

Write hexadecimal data into register.

<table style="border:1px;text-align:center;">
  <thead>
    <tr>
      <td rowspan="3">Display Hex Counter</td>
      <td colspan="7">7 segment display LEDs</td>
      <td rowspan="3">Register Hex</td>
    </tr>
    <tr>
      <td>G</td>
      <td>F</td>
      <td>E</td>
      <td>D</td>
      <td>C</td>
      <td>B</td>
      <td>A</td>
    </tr>
    <tr>
      <td>PB6</td>
      <td>PB5</td>
      <td>PB4</td>
      <td>PB3</td>
      <td>PB2</td>
      <td>PB1</td>
      <td>PB0</td>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>0</td>
      <td>0</td><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td>
      <td>3F</td>
    </tr>
    <tr>
      <td>1</td>
      <td>0</td><td>0</td><td>0</td><td>0</td><td>1</td><td>1</td><td>0</td>
      <td>06</td>
    </tr>
    <tr>
      <td>2</td>
      <td>1</td><td>0</td><td>1</td><td>1</td><td>0</td><td>1</td><td>1</td>
      <td>5B</td>
    </tr>
    <tr>
      <td>3</td>
      <td>1</td><td>0</td><td>0</td><td>1</td><td>1</td><td>1</td><td>1</td>
      <td>4F</td>
    </tr>
    <tr>
      <td>4</td>
      <td>1</td><td>1</td><td>0</td><td>0</td><td>1</td><td>1</td><td>0</td>
      <td>66</td>
    </tr>
    <tr>
      <td>5</td>
      <td>1</td><td>1</td><td>0</td><td>1</td><td>1</td><td>0</td><td>1</td>
      <td>6D</td>
    </tr>
    <tr>
      <td>6</td>
      <td>1</td><td>1</td><td>1</td><td>1</td><td>1</td><td>0</td><td>1</td>
      <td>7D</td>
    </tr>
    <tr>
      <td>7</td>
      <td>0</td><td>1</td><td>0</td><td>0</td><td>1</td><td>1</td><td>1</td>
      <td>27</td>
    </tr>
    <tr>
      <td>8</td>
      <td>1</td><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td>
      <td>7F</td>
    </tr>
    <tr>
      <td>9</td>
      <td>1</td><td>1</td><td>0</td><td>0</td><td>1</td><td>1</td><td>1</td>
      <td>67</td>
    </tr>
    <tr>
      <td>A</td>
      <td>1</td><td>0</td><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td>
      <td>5F</td>
    </tr>
    <tr>
      <td>B</td>
      <td>1</td><td>1</td><td>1</td><td>1</td><td>1</td><td>0</td><td>0</td>
      <td>7C</td>
    </tr>
    <tr>
      <td>C</td>
      <td>1</td><td>0</td><td>1</td><td>1</td><td>0</td><td>0</td><td>0</td>
      <td>58</td>
    </tr>
    <tr>
      <td>D</td>
      <td>1</td><td>0</td><td>1</td><td>1</td><td>1</td><td>1</td><td>0</td>
      <td>5E</td>
    </tr>
    <tr>
      <td>E</td>
      <td>1</td><td>1</td><td>1</td><td>1</td><td>0</td><td>1</td><td>1</td>
      <td>7B</td>
    </tr>
    <tr>
      <td>F</td>
      <td>1</td><td>1</td><td>1</td><td>0</td><td>0</td><td>0</td><td>1</td>
      <td>71</td>
    </tr>
  </tbody>
</table>

![image](https://github.com/yush2106/stm32-labs/blob/main/Practice1-hex-counter-for-7-segment-display/img/Practice1-hex-counter-for-7-segment-display-04.jpg)
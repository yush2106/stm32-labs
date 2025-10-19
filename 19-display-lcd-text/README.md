## LCD Display Text

NUCLEO-L476RG conntects pin4 to pin9 (PC4 to PC9) with the 1602A LCD.
Try to setup and display text on the LCD.

## Process step

Step 1: Set PC4 to PC9 for GPIO output.

![image](https://github.com/yush2106/stm32-labs/blob/main/19-display-lcd-text/img/19-display-lcd-text-01.jpg)

Step 2: Connect pins, PC4 to PC7, with 1602A LCD pins, D4 to D7. The power 3.3V and GND connect to VCC and GND of LCD.

![image](https://github.com/yush2106/stm32-labs/blob/main/19-display-lcd-text/img/19-display-lcd-text-02.jpg)

Step 3: LCD initialization.

<table style="text-align:center;">
  <thead>
    <tr>
      <td>No.</td>
      <td colspan=10>Signal of pins</td>
      <td>Description</td>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td colspan=10>Power On</td>
      <td></td>
    </tr>
    <tr>
      <td>2</td>
      <td colspan=10>Wait for more than 40 ms after Vcc rises.</td>
      <td></td>
    </tr>
    <tr>
      <td rowspan=2>3</td>
      <td>RS</td>
      <td>RW</td>
      <td>D7</td>
      <td>D6</td>
      <td>D5</td>
      <td>D4</td>
      <td>D3</td>
      <td>D2</td>
      <td>D1</td>
      <td>D0</td>
      <td rowspan=2></td>
    </tr>
    <tr>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <td>4</td>
      <td colspan=10>Wait for more than 4.1 ms</td>
      <td></td>
    </tr>
    <tr>
      <td rowspan=2>5</td>
      <td>RS</td>
      <td>RW</td>
      <td>D7</td>
      <td>D6</td>
      <td>D5</td>
      <td>D4</td>
      <td>D3</td>
      <td>D2</td>
      <td>D1</td>
      <td>D0</td>
      <td rowspan=2></td>
    </tr>
    <tr>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <td>6</td>
      <td colspan=10>Wait for more than 100 µs</td>
      <td></td>
    </tr>
    <tr>
      <td rowspan=2>7</td>
      <td>RS</td>
      <td>RW</td>
      <td>D7</td>
      <td>D6</td>
      <td>D5</td>
      <td>D4</td>
      <td>D3</td>
      <td>D2</td>
      <td>D1</td>
      <td>D0</td>
      <td rowspan=2></td>
    </tr>
    <tr>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <td>8</td>
      <td colspan=10>Delay</td>
      <td></td>
    </tr>
    <tr>
      <td rowspan=2>9</td>
      <td>RS</td>
      <td>RW</td>
      <td>D7</td>
      <td>D6</td>
      <td>D5</td>
      <td>D4</td>
      <td>D3</td>
      <td>D2</td>
      <td>D1</td>
      <td>D0</td>
      <td rowspan=2></td>
    </tr>
    <tr>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <td>10</td>
      <td colspan=10>Delay</td>
      <td></td>
    </tr>
    <tr>
      <td rowspan=2>11</td>
      <td>RS</td>
      <td>RW</td>
      <td>D7</td>
      <td>D6</td>
      <td>D5</td>
      <td>D4</td>
      <td>D3</td>
      <td>D2</td>
      <td>D1</td>
      <td>D0</td>
      <td rowspan=2>0x0028<br/>
      D4 (DL): 0 for 4-bit<br/>
      D3 (N): 1 for 2-Line<br/>
      D2 (F): 0 for 5 * 8 font
      </td>
    </tr>
    <tr>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <td>12</td>
      <td colspan=10>Delay</td>
      <td></td>
    </tr>
    <tr>
      <td rowspan=2>13</td>
      <td>RS</td>
      <td>RW</td>
      <td>D7</td>
      <td>D6</td>
      <td>D5</td>
      <td>D4</td>
      <td>D3</td>
      <td>D2</td>
      <td>D1</td>
      <td>D0</td>
      <td rowspan=2>0x000F<br/>
      D2 (D): 1 for display on<br/>
      D1 (C): 1 for show cursor<br/>
      D0 (B): 1 for blinking cursor
      </td>
    </tr>
    <tr>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
    </tr>
    <tr>
      <td>14</td>
      <td colspan=10>Delay</td>
      <td></td>
    </tr>
    <tr>
      <td rowspan=2>15</td>
      <td>RS</td>
      <td>RW</td>
      <td>D7</td>
      <td>D6</td>
      <td>D5</td>
      <td>D4</td>
      <td>D3</td>
      <td>D2</td>
      <td>D1</td>
      <td>D0</td>
      <td rowspan=2>0x0001<br/>
      D0 : 1 for clear display
      </td>
    </tr>
    <tr>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
    </tr>
    <tr>
      <td>16</td>
      <td colspan=10>Delay</td>
      <td></td>
    </tr>
    <tr>
      <td rowspan=2>17</td>
      <td>RS</td>
      <td>RW</td>
      <td>D7</td>
      <td>D6</td>
      <td>D5</td>
      <td>D4</td>
      <td>D3</td>
      <td>D2</td>
      <td>D1</td>
      <td>D0</td>
      <td rowspan=2>0x0006<br/>
      D1 (I/D): 1 for increase cursor position automatically<br/>
      D0 (SH): 0 for disable shift entire LCD
      </td>
    </tr>
    <tr>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>0</td>
    </tr>
    <tr>
      <td>18</td>
      <td colspan=10>Delay</td>
      <td></td>
    </tr>
  </tbody>
</table>

Step 4: Write character values into register sequentially.

![image](https://github.com/yush2106/stm32-labs/blob/main/19-display-lcd-text/img/19-display-lcd-text-03.jpg)
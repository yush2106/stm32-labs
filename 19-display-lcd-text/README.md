## LCD Display Text

NUCLEO-L476RG conntects pin4 to pin9 (PA4 to PA9) with the 1602A LCD display.
Try to setup and display text on the LCD.

## Process step

Step 1: Set PA4 to PA9 for GPIO output.

![image](https://github.com/yush2106/stm32-labs/blob/main/19-display-lcd-text/img/19-display-lcd-text-01.jpg)

Step 2: Connect pins, PA4 to PA7, with 1602A LCD display pins, DB4 to DB7. The power 3.3V and GND connect to VCC and GND of LCD display.

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
      <td>DB7</td>
      <td>DB6</td>
      <td>DB5</td>
      <td>DB4</td>
      <td>DB3</td>
      <td>DB2</td>
      <td>DB1</td>
      <td>DB0</td>
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
      <td>DB7</td>
      <td>DB6</td>
      <td>DB5</td>
      <td>DB4</td>
      <td>DB3</td>
      <td>DB2</td>
      <td>DB1</td>
      <td>DB0</td>
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
      <td>DB7</td>
      <td>DB6</td>
      <td>DB5</td>
      <td>DB4</td>
      <td>DB3</td>
      <td>DB2</td>
      <td>DB1</td>
      <td>DB0</td>
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
      <td colspan=10>Delay</td>
      <td></td>
    </tr>
    <tr>
      <td rowspan=2>7</td>
      <td>RS</td>
      <td>RW</td>
      <td>DB7</td>
      <td>DB6</td>
      <td>DB5</td>
      <td>DB4</td>
      <td>DB3</td>
      <td>DB2</td>
      <td>DB1</td>
      <td>DB0</td>
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
      <td>8</td>
      <td colspan=10>Delay</td>
      <td></td>
    </tr>
    <tr>
      <td rowspan=2>9</td>
      <td>RS</td>
      <td>RW</td>
      <td>DB7</td>
      <td>DB6</td>
      <td>DB5</td>
      <td>DB4</td>
      <td>DB3</td>
      <td>DB2</td>
      <td>DB1</td>
      <td>DB0</td>
      <td rowspan=2>0x0028<br/>
      DB4 (DL): 0 for 4-bit<br/>
      DB3 (N): 1 for 2-Line<br/>
      DB2 (F): 0 for 5 * 8 font
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
      <td>10</td>
      <td colspan=10>Delay</td>
      <td></td>
    </tr>
    <tr>
      <td rowspan=2>11</td>
      <td>RS</td>
      <td>RW</td>
      <td>DB7</td>
      <td>DB6</td>
      <td>DB5</td>
      <td>DB4</td>
      <td>DB3</td>
      <td>DB2</td>
      <td>DB1</td>
      <td>DB0</td>
      <td rowspan=2>0x000F<br/>
      DB2 (D): 1 for display on<br/>
      DB1 (C): 1 for show cursor<br/>
      DB0 (B): 1 for blinking cursor
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
      <td>12</td>
      <td colspan=10>Delay</td>
      <td></td>
    </tr>
    <tr>
      <td rowspan=2>13</td>
      <td>RS</td>
      <td>RW</td>
      <td>DB7</td>
      <td>DB6</td>
      <td>DB5</td>
      <td>DB4</td>
      <td>DB3</td>
      <td>DB2</td>
      <td>DB1</td>
      <td>DB0</td>
      <td rowspan=2>0x0001<br/>
      DB0 : 1 for clear display
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
      <td>14</td>
      <td colspan=10>Delay</td>
      <td></td>
    </tr>
    <tr>
      <td rowspan=2>15</td>
      <td>RS</td>
      <td>RW</td>
      <td>DB7</td>
      <td>DB6</td>
      <td>DB5</td>
      <td>DB4</td>
      <td>DB3</td>
      <td>DB2</td>
      <td>DB1</td>
      <td>DB0</td>
      <td rowspan=2>0x0006<br/>
      DB1 (I/D): 1 for auto increase cursor position
      DB0 (SH): 0 for disable shift entire lcd
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
      <td>16</td>
      <td colspan=10>Delay</td>
      <td></td>
    </tr>
  </tbody>
</table>

Step 4: Write character values into register sequentially.

![image](https://github.com/yush2106/stm32-labs/blob/main/19-display-lcd-text/img/19-display-lcd-text-03.jpg)
## Number Counter of 7 Segment Display

The 7 segment display pins connect to GPIO Pin0 to Pin6, PC0 to PC6.

Increase counter number every second and display number for the 7 segment display.

## Process steps

Step 1: Set the counter number to 0.

Step 2: Write hexadecimal numbers to register.

Step 3: Increase the counter number.

Step 4: Reset the counter number to 0 when it greater than 9.

Step 5: Delay.

![image](https://github.com/yush2106/stm32-labs/blob/main/10-seven-segment-display-counter/img/10-seven-segment-display-counter-01.jpg)

![image](https://github.com/yush2106/stm32-labs/blob/main/10-seven-segment-display-counter/img/10-seven-segment-display-counter-02.jpg)

<table style="text-align:center;">
  <thead>
    <tr>
      <td  rowspan=2>7 segment display number</td>
      <td>G</td>
      <td>F</td>
      <td>E</td>
      <td>D</td>
      <td>C</td>
      <td>B</td>
      <td>A</td>
      <td  rowspan=2>register hexadecimal number</td>
    </tr>
    <tr>
      <td>PC6</td>
      <td>PC5</td>
      <td>PC4</td>
      <td>PC3</td>
      <td>PC2</td>
      <td>PC1</td>
      <td>PC0</td>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>3F</td>
    </tr>
    <tr>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>06</td>
    </tr>
    <tr>
      <td>2</td>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>5B</td>
    </tr>
    <tr>
      <td>3</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>4F</td>
    </tr>
    <tr>
      <td>4</td>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>66</td>
    </tr>
    <tr>
      <td>5</td>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>6D</td>
    </tr>
    <tr>
      <td>6</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>7D</td>
    </tr>
    <tr>
      <td>7</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>07</td>
    </tr>
    <tr>
      <td>8</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>7F</td>
    </tr>
    <tr>
      <td>9</td>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>6F</td>
    </tr>
  </tbody>
</table>

No. 3 of 7 Segment Display

![image](https://github.com/yush2106/stm32-labs/blob/main/10-seven-segment-display-counter/img/10-seven-segment-display-counter-03.jpg)

No. 8 of 7 Segment Display

![image](https://github.com/yush2106/stm32-labs/blob/main/10-seven-segment-display-counter/img/10-seven-segment-display-counter-04.jpg)
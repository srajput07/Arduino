# Arduino
 Smart Plant Monitoring & Alert System using Arduino

This project monitors the condition of a plant using sensors for **temperature**, **soil moisture**, **gas/smoke**, and **tilt**, and displays the information on a **16x2 LCD**. It also alerts the user via a **buzzer** if critical thresholds are crossed.

 Hardware Used

- Arduino Uno
- 16x2 LCD (parallel, non-I2C)
- TMP36 Temperature Sensor
- Soil Moisture Sensor
- Gas Sensor (simulated using potentiometer)
- Tilt Sensor (2-pin)
- Buzzer
- Potentiometer (for LCD contrast)
- Breadboard and jumper wires

 Circuit Overview

- LCD connected using 4-bit mode (RS, E, D4-D7)
- TMP36 on A0, Soil sensor on A1, Gas sensor on A2
- Tilt sensor on D7, Buzzer on D8
- 10k potentiometer used to control LCD contrast



 Alert Logic:
- Soil moisture < 400 → Dry → Buzzer ON
- Gas level > 500 → Alert → Buzzer ON
- Tilt sensor triggered → Alert → Buzzer ON



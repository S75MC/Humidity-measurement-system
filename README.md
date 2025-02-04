Humidity sensor in plants

Description : 
Managing water resources in agriculture is challenging, with overwatering or underwatering leading to waste and reduced crop yields. The growing demand for continuous soil moisture monitoring highlights the need for a reliable sensor system. This solution provides real-time moisture data, helping farmers make informed irrigation decisions, improving efficiency, and reducing waste.

Features
 A: Soil Moisture Measurement and Irrigation Control Users can 
monitor soil moisture levels and automatically irrigate plants based on the detected 
moisture level.

B: Soil Moisture Monitoring and Manual Irrigation Control 
Users can monitor soil moisture levels and manually trigger irrigation based on the 
system’s readings. 
User Stories


Requirements
Hardware:
Arduino:
Soil Moisture Sensor (SMS):
Rate relay: 
Water Pump
rrigation Pipes (Irrigation Pipes)
Wiring

Software:
Arduino IDE (C++)


How to Use
Clone the repository
رابط github
Open the .ino file in Arduino IDE.
Connect the hardware components based on the system diagram.
Upload the code to the Arduino board


How to User Flow 		

1) Power On: The user powers on the Arduino-based irrigation system, which starts the initialization process.


2) System Calibration: The system performs a self-check, verifying the sensors and relay connections.



3) Moisture Level Monitoring: The soil moisture sensor continuously monitors the soil's moisture level and sends data to the Arduino.


4) Threshold Check: The system compares the moisture level to a preset threshold.
If the soil moisture is below the threshold (dry), the system triggers the relay to turn on the water pump.
If the soil moisture is above the threshold (wet), the system keeps the pump off.

5) Irrigation: When the pump is activated, water is pumped through the irrigation pipes to the plants.


6) Continuous Monitoring: The system continually checks the soil moisture and adjusts the pump's status as needed to maintain optimal moisture levels


System Design
Soil Moisture Detection (Soil Moisture Detection) 🌱💧

Uses low soil moisture sensitivity.

Sends sensitive data to the Arduino, which is analyzed to determine whether the soil is necessary for irrigation.

Water Pump Control (Pump Control) 🚰⚡

When the moisture level drops below the limit, the Arduino sends a signal to the relay module to turn on the pump and pump water.

Once the moisture reaches the desired level, the pump is automatically stopped to command irrigation.

Display and Alerts (Display of data and alerts) 📟🔔

The LCD screen can be used for the status and condition of the pump (on/off).

LED lights or alarm alert can be added to inform the user during the flow process or when the pump is turned on.

Power and Automation (Power and Printing) 🔋🤖

The system operates fully automatically without the need for human intervention.
It can be powered by battery or external power source and the power is always on.


Authors   

Lyan Majed Alharbi 
Shatha Alkabkabi
Ghala trad Alshreef
Albisslan Ahmad

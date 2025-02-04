# Humidity Sensor in Plants

## Description 🌱💧

Managing water resources in agriculture is challenging, with overwatering or underwatering leading to waste and reduced crop yields. The growing demand for continuous soil moisture monitoring highlights the need for a reliable sensor system. This solution provides real-time moisture data, helping farmers make informed irrigation decisions, improving efficiency, and reducing waste.

## Features 🚀

### A: Soil Moisture Measurement and Irrigation Control

- Users can monitor soil moisture levels and automatically irrigate plants based on the detected moisture level.

### B: Soil Moisture Monitoring and Manual Irrigation Control

- Users can monitor soil moisture levels and manually trigger irrigation based on the system’s readings.

---

## Requirements ⚙️

### Hardware 🛠️

- **Arduino Uno**
- **Soil Moisture Sensor (SMS)**
- **Relay Module**
- **Water Pump**
- **Irrigation Pipes**
- **Wiring**

### Software 💻

- **Arduino IDE (C++)**

---

## How to Use 🚀

1. **Clone the repository:**
   ```bash
   git clone <https://github.com/S75MC/Humidity-measurement-system/blob/main/Build_a_auto_watering_system_for_plants_using_Arduino.inob>
   ```
2. **Open the .ino file in Arduino IDE.**
3. **Connect the hardware components based on the system diagram.**
4. **Upload the code to the Arduino board.**

---

## User Flow 🔄

1️⃣ **Power On:** The user powers on the Arduino-based irrigation system, which starts the initialization process.

2️⃣ **System Calibration:** The system performs a self-check, verifying the sensors and relay connections.

3️⃣ **Moisture Level Monitoring:** The soil moisture sensor continuously monitors the soil's moisture level and sends data to the Arduino.

4️⃣ **Threshold Check:** The system compares the moisture level to a preset threshold:

- If the soil moisture is **below the threshold (dry),** the system triggers the relay to turn on the water pump.
- If the soil moisture is **above the threshold (wet),** the system keeps the pump off.

5️⃣ **Irrigation:** When the pump is activated, water is pumped through the irrigation pipes to the plants.

6️⃣ **Continuous Monitoring:** The system continually checks the soil moisture and adjusts the pump's status as needed to maintain optimal moisture levels.

---

## System Design 🏗️

### 1️⃣ Soil Moisture Detection 🌱💧

- Uses low soil moisture sensitivity.
- Sends data to the Arduino, which analyzes it to determine whether irrigation is needed.

### 2️⃣ Water Pump Control 🚰⚡

- When moisture level drops below the limit, Arduino sends a signal to the relay module to activate the pump.
- Once moisture reaches the desired level, the pump is stopped automatically.

### 3️⃣ Display and Alerts 📟🔔

- LCD screen can display the pump status (ON/OFF).
- LED lights or alarms can be added to notify users when the pump is running.

### 4️⃣ Power and Automation 🔋🤖

- Fully automated system requiring no human intervention.
- Powered by a battery or external power source.

---

## Authors ✍️

- **Lyan Majed Alharbi**
- **Shatha Alkabkabi**
- **Ghala Trad Alshreef**
- **Albisslan Ahmad**


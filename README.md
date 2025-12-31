# 🔥 Smart Fire and Safety Monitoring System for Power Distribution Substations

## 📌 Project Overview
The **Smart Fire and Safety Monitoring System** is an embedded system–based solution designed to enhance fire safety in **power distribution substations**.  
The system detects fire-related hazards and automatically performs safety actions such as alarm activation, power isolation, and CO₂-based fire suppression.

> ⚠️ This project is **validated using Tinkercad simulation** and is **ready for real-world deployment** by replacing simulated components with actual hardware.

---

## 🖼️ Project Preview
![Project Overview](images/project_overview.png)

*(Add system overview or simulation screenshot here)*

---

## 🎯 Objectives
- Real-time fire hazard detection  
- Automated emergency response  
- Power isolation during fire incidents  
- CO₂ suppression activation  
- Local monitoring using LCD display  
- Reduce dependency on human intervention  

---

## ⚙️ System Features
- 🔥 Flame, smoke, and temperature-based detection  
- ⚡ Automatic power cut-off logic  
- 🧯 CO₂ suppression control  
- 🚨 Buzzer and visual alarm alerts  
- 📟 16×2 LCD for system status  
- 🔒 System lock until manual reset  

---

## 🧠 Working Principle
1. Sensors continuously monitor fire-related conditions.  
2. If **any hazard** is detected:
   - Alarm and buzzer are activated  
   - Main power supply is isolated  
   - CO₂ suppression is triggered  
   - LCD displays emergency alerts  
   - System enters **locked state**  
3. The system resets only after **manual authorization**.

---

## 🖼️ Working Flow Diagram
![System Flow](images/system_flow_diagram.png)

*(Add block diagram / flowchart here)*

---

## 🧰 Components Used

### 🔹 Simulation Components
- Arduino Uno  
- Push Buttons (sensor simulation)  
- LEDs (relay & CO₂ simulation)  
- 16×2 LCD Display  
- Buzzer  

### 🔹 Real Implementation (Proposed)
- IR Flame Sensor (KY-026)  
- Smoke/Gas Sensor (MQ-2)  
- Temperature Sensor (DS18B20)  
- Relay Module  
- CO₂ Solenoid Valve  

> ℹ️ In simulation, **push buttons and LEDs are used as logical equivalents** due to platform limitations.

---

## 🖼️ Simulation Setup
![Simulation Setup](images/simulation_setup.png)

*(Add Tinkercad circuit screenshot here)*

---

## 🧪 Simulation & Testing
- Platform: **Tinkercad Circuits**
- Push buttons simulate sensor triggers
- LEDs represent power cut-off and CO₂ valve
- Temperature values are simulated for fire conditions
- Multiple test cases validated system behavior

---

## 📊 Results
- Immediate hazard detection (simulation-based)  
- Automated execution of safety protocols  
- Stable system operation without false alarms  
- Clear emergency indication on LCD  
- Secure reset mechanism  

---

## 🖼️ Emergency Mode Output
![Emergency Mode](images/emergency_mode.png)

*(Add LCD emergency screen screenshot here)*

---

## 🚀 Future Enhancements
- Real sensor and actuator integration  
- IoT connectivity (Wi-Fi / GSM)  
- Remote alerts and monitoring  
- Data logging and analytics  
- SCADA system integration  
- AI-based fire prediction  

---

## 🏫 Academic Information
- **Department:** CSE (Internet of Things)  
- **Institution:** Bakhtiyarpur College of Engineering, Bihar  
- **Academic Year:** 2024–2025  
- **Project Type:** Simulation-based Embedded System  

---


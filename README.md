# RGB LED Control Using LabVIEW and Arduino

## 📌 Project Overview
This project demonstrates serial communication between **LabVIEW** and an **Arduino Uno** to control an **RGB LED**.  
The system allows:
- Turning each LED color (Red, Green, Blue) **ON/OFF**
- Adjusting brightness of each color using **PWM**
- Real-time control via a LabVIEW graphical user interface

Communication is implemented using **VISA Serial (USB)**.

---

## 🧠 System Architecture
- **PC (LabVIEW)** – User interface, control logic, serial communication
- **Arduino Uno** – Receives commands and controls RGB LED
- **RGB LED (common cathode)** – Visual output device

---

## 🛠️ Hardware Used
- Arduino Uno
- RGB LED (common cathode)
- 3 × current-limiting resistors (220–330 Ω)
- USB cable
- Jumper wires

---

## 💻 Software Used
- LabVIEW (with VISA support)
- Arduino IDE
- ? USB-to-Serial driver (CH340 for clone boards)

---

## 🔌 Wiring
| Color | Arduino Pin | Type |
| :--- | :--- | :--- |
| **Red** | D9 | PWM |
| **Green** | D11 | PWM |
| **Blue** | D10 | PWM |
| **Common** | GND | Ground |

---

## 📡 Serial Protocol
Commands sent from LabVIEW to Arduino:

### ON / OFF Control
- `R1` → Red ON
- `R0` → Red OFF
- `G1` → Green ON
- `G0` → Green OFF
- `B1` → Blue ON
- `B0` → Blue OFF

### PWM Brightness Control
- `RP0` – `RP255` → Red brightness
- `GP0` – `GP255` → Green brightness
- `BP0` – `BP255` → Blue brightness

**Example sequence:**
```text
RP128
GP255
BP30
```

## 🧾 Arduino Code
The source code for the microcontroller is located in the `arduino_rgb_pwm.ino` file within this repository.

---

## 🖥️ LabVIEW Interface
The LabVIEW front panel includes:
- Toggle buttons for each color
- PWM sliders for brightness control
- VISA COM port selector
- LED indicators reflecting current state

---

## 📷 Screenshots

| **Front Panel GUI** | **Block Diagram (Logic)** |
|:---:|:---:|
| <img src="https://github.com/user-attachments/assets/078187a5-f595-4f3e-86fc-6dc859f5a2f4" width="100%"> | <img src="https://github.com/user-attachments/assets/99135bc6-d49c-492e-914b-5ccc7e4dd051" width="100%"> |
| *User interface for real-time RGB control* | *LabVIEW code handling VISA & PWM logic* |

---

## 🎯 Project Purpose
This project was created as part of an academic LabVIEW course to demonstrate:
- VISA serial communication
- Hardware–software integration
- PWM signal generation
- GUI-based embedded control

---

## 👥 Authors
- Krzysztof Kwiatkowski

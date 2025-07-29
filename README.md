
# 🔬 Advanced Handheld Oscilloscope

A compact, portable oscilloscope designed using Arduino Nano and OLED display to visualize electrical signals in real time. This project is ideal for students, hobbyists, and engineers needing a cost-effective signal analysis tool on-the-go.

---

## 📌 Project Overview

The **Advanced Handheld Oscilloscope** is a miniaturized oscilloscope offering core signal monitoring functions typically found in larger models. Built using Arduino Nano and a 128x64 OLED display, the system enables users to:

- Capture AC/DC signals
- Display real-time waveforms
- Measure signal parameters like amplitude, frequency, and duty cycle

---

## 🚀 Features

- 📉 Real-time waveform display
- 📦 Compact and battery-powered
- 🧠 Signal conditioning and filtering
- 🧾 User interface via tactile switches
- 🖥️ OLED screen for clear visuals
- 💻 Arduino-based control and data acquisition

---

## 🔧 Components Used

| Component         | Description                             |
|------------------|-----------------------------------------|
| Arduino Nano      | Microcontroller for signal processing   |
| 128x64 OLED Display | Displays real-time waveforms            |
| Resistors & Capacitors | Signal conditioning circuitry         |
| Tactile Switches  | User input for control functions        |
| Breadboard        | For circuit prototyping                 |
| Connecting Wires  | Electrical interconnections             |

---

## 📷 Block Diagram

```
[Input Signal] → [Amplifier/Attenuator] → [Signal Conditioning] → [Arduino ADC]  
→ [Microcontroller Processing] → [OLED Display Output]
```

---

## 🔌 Circuit Diagram

See the `circuit_diagram.png` file in the repo for complete wiring.

Key Notes:
- Analog signal is scaled using resistive divider and capacitors
- Inputs are read using A0/A1 on Arduino
- OLED uses I2C: A4 (SDA), A5 (SCL)
- Tactile switches connected to D2-D5

---

## 📈 Results

- Successfully captured and displayed sine waveforms up to 1 kHz
- Clear visualization on OLED display
- Responsive control via push-buttons
- Effective for testing, education, and fieldwork

---

## 🌍 Applications

- 🧪 Educational labs and STEM learning
- 🛠 DIY electronics and circuit debugging
- 🚗 Automotive signal diagnostics
- 🌱 Renewable energy system testing (solar, wind)
- 📻 Communication signal verification
- ⚕️ Portable medical signal monitoring (e.g., ECG)

---

## ✅ Advantages

- ✅ Lightweight and portable
- ✅ Affordable and beginner-friendly
- ✅ Versatile for AC/DC signal types
- ✅ Open-source and customizable

## ⚠️ Limitations

- ⚡ Lower bandwidth and sampling rate
- 📺 Smaller display resolution
- 🧠 Limited memory and signal precision

---

## 📚 Literature Support

Implemented with insights from:
- Arduino + LabVIEW oscilloscopes
- FPGA-based DSO implementations
- Sound-card and virtual oscilloscope research
- Embedded DSO with 1GSPS sampling

---

## 📦 Future Scope

- 📡 Upgrade to higher frequency range
- 📊 Add FFT and spectrum analysis
- 📱 Smartphone or cloud integration
- ⚙️ Touchscreen UI with menu navigation
- 🤖 AI-based waveform recognition

---

## 👩‍💻 Authors

> Developed by Final Year ECE Students, HKBK College of Engineering (2024–25)

---

## 📝 References

[1] M. Zuo et al., "Field Trial of Real-Time 400-Gb/s... (ECOC 2023)"  
[2] A. Elfasi et al., "Oscilloscope using Arduino + LabVIEW", GECS 2017  
[3] V. Nair, "ATMEGA328P MCU Signal Viewer", I2CT 2018  
[4] Y. Ren, "Pocket Instruments in Education", FIE 2020  

---

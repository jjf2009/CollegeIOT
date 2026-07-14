# Arduino IoT Lab Experiments & Projects

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Platform](https://img.shields.io/badge/platform-Arduino-orange.svg)
![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)

A comprehensive collection of **Internet of Things (IoT) lab experiments** and **Arduino projects** tailored for embedded systems enthusiasts, students, and educators. This repository contains well-documented source code (`.hex` and project files) for various microcontroller-based applications involving sensors, actuators, and displays.

## 🚀 Key Features & Experiments

This repository is highly optimized for learning and implementing core IoT concepts. It covers a wide range of practical hardware integrations:

* **Display Interfaces**: I2C LCD interfacing for real-time data visualization.
* **Sensor Integration**:
  * Proximity Sensors
  * Temperature Sensors
  * LDR (Light Dependent Resistors)
  * Touch Sensors
  * IR (Infrared) Sensors
  * Heartbeat Monitors
* **Actuators & Motor Control**:
  * Servo motor control via Potentiometers and Serial communication.
  * LED fading and blinking mechanisms.
* **Signal Modulation**:
  * Pulse Width Modulation (PWM) using Potentiometers and LDRs.
* **Real-World Simulations**:
  * One-way and Four-way Traffic Light Controllers.

## 📁 Repository Structure

The projects are categorized into distinct modules, making it easy to find specific code implementations:

- `IR_with_Lcd.hex` - Infrared sensor integration with LCD output.
- `Proximity_with_lcd.hex` - Proximity detection systems.
- `Temp_with_lcd.hex` - Temperature monitoring.
- `blinking_led_with_Lcd.hex` - Basics of GPIO control.
- `fade_amount_with_lcd.hex` - Advanced LED fading.
- `four_way_traffic_light_with_lcd.hex` - Complex traffic logic simulation.
- `heartbeat_normal_with_lcd.hex` - Biometric sensor data reading.
- `ldr_with_lcd.hex` - Light detection and measurement.
- `one_way_traffic_light_with_lcd.hex` - Simple traffic light sequence.
- `pluse_width_modulation_using_ldr_with_lcd.hex` - Light-based PWM control.
- `pulse_width_modulation_using_potentiometer__with_lcd.hex` - Analog input PWM control.
- `servo_using_poteniometer_with_lcd.hex` - Analog servo positioning.
- `servo_with_serial_with_lcd.hex` - Serial command servo control.
- `touch_with_lcd.hex` - Capacitive touch sensing.
- `LabExperiments/` - Contains structured, step-by-step lab experiments (Expt2, EXPT3, Expt4).

## 💡 How to Use

1. **Clone the repository:**
   ```bash
   git clone https://github.com/jjf2009/arduino-iot-lab-experiments.git
   ```
2. **Flash the Code:**
   Upload the relevant code to your Arduino board using the Arduino IDE or PlatformIO.
3. **Wire the Circuit:**
   Follow standard Arduino pinouts for LCDs (often via I2C), Servos, and specific sensors as indicated by the code.

## 🔍 SEO & Keywords

`Internet of Things`, `IoT`, `Arduino`, `Embedded Systems`, `Microcontrollers`, `C++`, `Sensors`, `Actuators`, `LCD Interfacing`, `PWM`, `Servo Control`, `Hardware`, `Engineering`, `College Lab Experiments`.

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the [issues page](../../issues).

---
*If you find this repository helpful for your IoT journey, please consider giving it a ⭐!*

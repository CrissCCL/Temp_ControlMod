# 🚀 Temperature Control Module

## 📖 Overview
This low-cost module was designed and built to perform hands-on experiments in Digital Control. The system is controlled using an Arduino, heat is modulated with a TIP31C transistor, and temperature is measured using a TMP36 sensor.  

It provides a simple and practical platform for learning control theory in a laboratory environment.

> ⚠️ **Note:** This project is currently under updates. Features and hardware are subject to change.

## 📂 Contents
- `/Hardware` → schematic, PCB, Gerbers.
- `/control_temp_LC` → C code for Arduino.
- `/docs` → photos

## 🔄 Control Loop
<p align="center">
<img src="docs/esquema control temp.png" alt="Diagrama sistema" width="500">
</p>

### Controlled Variables
- **Temperature** → Temperature value control (stabilization)

## 📐 Digital PID Control

The Module uses a discrete PI controller implemented on a Arduino microcontroller.  
The control law in the digital domain is expressed as:

$$
u(n) = u(n-1) + K_0 e(n) + K_1 e(n-1)
$$

$$
V_{PWM}(n) = V_{PWM}(n-1) + K_0 e(n) + K_1 e(n-1)
$$
### Parameters:

$$
K_0 = K_p + \frac{K_p}{2T_i} T_s
$$

$$
K_1 = -K_p + \frac{K_p}{2T_i} T_s
$$

## 🖼️ Render 3D PCB Version 2
<p align="center">
<img src="docs/procesotemp.png" alt="PCB Render" width="500">
</p>
---

## ⚡ Physical Prototype
<p align="center">
<img src="docs/armado.jpg" alt="Foto del prototipo" width="400">
</p>
<p align="center">
<img src="docs/setup_completo.jpg" alt="Foto del prototipo" width="400">
</p>

## 📜 License
MIT License  

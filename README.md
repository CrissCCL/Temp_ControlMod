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

Digital PI controller implemented for temperature measured,

$$
V_{PWM}(n) = V_{PWM}(n-1) + K_0 e(n) + K_1 e(n-1)
$$

### Parameters:
The parameters are adjusted for temperature measured,

$$
K_0 = K_p + \frac{K_p}{2T_i} T_s
$$

$$
K_1 = -K_p + \frac{K_p}{2T_i} T_s
$$

## 🔉 Signal Processing: Low-Pass IIR Filter (1st Order)

To reduce measurement noise, a **first-order IIR low-pass filter** was applied to the temperature signal before feeding it to the controller and the ARX model.  

### 🔹 Filter Equation  

$$
y(k) = \alpha \cdot x(k) + (1 - \alpha) \cdot y(k-1)
$$  

Where:  
- $$x(k)$$: raw sensor measurement at time step $$k$$  
- $$y(k)$$: filtered output  
- $$\alpha$$: smoothing factor, $$(0<\alpha<1)$$ 


## 🧪 PI Control Test and ARX Model Comparison  

A test was performed using a **PI controller** applied to the temperature control module.  
The experimental results were compared against a **linear ARX model** identified from system data.  

### 🔹 General ARX Model Equation  

The ARX (Auto-Regressive with eXogenous input) model is defined as:  

$$
y(k) + a_1 y(k-1) + a_2 y(k-2) + \dots + a_{n_a} y(k-n_a) =
b_1 u(k-1) + b_2 u(k-2) + \dots + b_{n_b} u(k-n_b) + e(k)
$$  

Where:  
- $$y(k)$$: system output at sample $$k$$ 
- $$u(k)$$: input signal at sample $$k$$  
- $$( a_i, b_j)$$: ARX parameters  
- $$( n_a, n_b)$$: model orders  
- $$e(k) $$: disturbance/noise  

### 🔹 Results Overview  
- ✅ The PI controller improved **temperature tracking** and reduced overshoot.  
- 📉 The ARX model captured the main dynamics, with small discrepancies due to nonlinear heat transfer effects.  
- ⚖️ The comparison confirms the applicability of ARX models for **thermal system control design**.  


### 🔹 Experimental Plots  

<p align="center">
<img src="docs/controlSim_Exp2.png" alt="ARX vs Experimental Comparison (Temperature)" width="500">
</p>


## 🖼️ Render 3D PCB Version 2
<p align="center">
<img src="docs/procesotemp.png" alt="PCB Render" width="500">
</p>

## ⚡ Physical Prototype

<table>
  <tr>
    <td align="center">
      <img src="docs/armado.jpg" alt="Foto del prototipo" width="400"><br>
      <sub>Device connections</sub>
    </td>
    <td align="center">
      <img src="docs/setup_completo.jpg" alt="Foto del prototipo" width="400"><br>
      <sub>Complete setup</sub>
    </td>
  </tr>
</table>

## 📜 License
MIT License  

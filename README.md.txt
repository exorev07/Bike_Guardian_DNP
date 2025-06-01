# 🚴‍♂️ Bike Guardian

**A smart ultrasonic-based alert system to enhance cyclist safety on roads.**

Bike Guardian is a low-cost, Arduino-powered system designed to alert bicycle riders of approaching vehicles from behind. Using ultrasonic sensors, it detects proximity and provides visual and audio warnings to the cyclist, improving awareness and reducing the risk of accidents.

---

## ⚙️ How It Works

- **Three HC-SR04 ultrasonic sensors** are mounted at the rear of the bicycle to detect vehicles within a 45° field.
- The sensors continuously measure the distance to objects behind the rider.
- An **Arduino Uno** processes the distance data and determines direction:
  - If a vehicle approaches from the left, the **left LED** lights up.
  - If from the right, the **right LED** lights up.
  - If directly behind (or both sides), **both LEDs** activate.
- A **buzzer** also sounds to alert the rider in real time.

This simple yet effective setup improves rider awareness without requiring complex infrastructure or expensive components.

---

## 🧾 File
- `Bike_Guardian_DNP.ino` – Arduino source code

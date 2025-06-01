# 🚴‍♂️ Bike Guardian

**A smart ultrasonic-based alert system to enhance cyclist safety on roads.**

Bike Guardian is a low-cost, Arduino-powered system designed to alert bicycle riders of approaching vehicles from behind. Using ultrasonic sensors, it detects proximity and provides visual and audio warnings to the cyclist, improving awareness and reducing the risk of accidents.

---

## 🔩 Components Used

| Component                  | Quantity | Description                             |
|---------------------------|----------|-----------------------------------------|
| HC-SR04 Ultrasonic Sensor | 3x       | Detects approaching vehicles            |
| Red DIP LED               | 3x       | Visual alerts for direction             |
| 5V Passive Buzzer         | 1x       | Audible alert for proximity warning     |
| Arduino Uno R3            | 1x       | Microcontroller for processing signals  |
| 9V Battery + Holder       | 1x       | Power supply for the system             |
| ABS Brackets              | 3x       | Mount sensors on the bicycle            |
| Jumper Wires              | As needed | Electrical connections                   |

## ⚙️ How It Works

- **Three HC-SR04 ultrasonic sensors** are mounted at the rear of the bicycle to detect vehicles within a 45° field.
- The sensors continuously measure the distance to objects behind the rider.
- An **Arduino Uno** processes the distance data and determines direction:
  - If a vehicle approaches from the left, the **left LED** lights up.
  - If from the right, the **right LED** lights up.
  - If directly behind (or both sides), **both LEDs** activate.
- The code is designed logically such that each LED blinks strategically depending on the distance of the vehicle approaching the rider.
- A **buzzer** also sounds to alert the rider in real time if the vehicle is in dangerously close vicinity.

This simple yet effective setup improves rider awareness without requiring complex infrastructure or expensive components. 

## Summary:

Bike Guardian is an Arduino-based safety system designed to protect cyclists from rear-approaching vehicles. It uses three ultrasonic sensors mounted at the back of the bicycle to detect objects within a 45° field of view. Based on the direction of the approaching vehicle, the system triggers LEDs on the handlebar (left, right, or both), activates a buzzer to alert the rider, and also activates the rear LEDs to alert the approaching traffic in case of low visibility. This enhances situational awareness in real-time, especially in low-visibility conditions, making cycling on busy roads safer and more confident.

---

## 👤 About the Author

**Ekansh Arohi (@exorev07)**  
Data Science & AI undergrad at IIIT Naya Raipur 
Passionate about electronics, smart hardware prototyping, and real-world problem solving through tech.
[🔗 LinkedIn Profile](https://www.linkedin.com/in/ekansharohi)

> “Find what you love and let it kill you.”

# 🍋 AI-Powered Lemon Sorting System

This project implements a real-time lemon sorting machine using computer vision (YOLOv8) and microcontroller-based control (ESP32). Lemons are classified as 'Good' or 'Bad' based on quality, and sorted accordingly using a servo and a conveyor system.

## 🔍 Features

- Real-time object detection with YOLOv8
- Communication between PC and ESP32 via Serial
- Controls a DC motor (conveyor) and a servo motor (for sorting)
- Custom dataset trained on lemon images

## 🛠 Hardware Components

- ESP32 microcontroller
- Servo motor
- DC motor (with motor driver or relay)
- USB webcam
- PC with GPU (for YOLOv8 inference)

## 💡 Software Components

- YOLOv8 (Ultralytics)
- OpenCV
- Python for PC-side logic
- Arduino C++ for ESP32

## 🧠 Trained Model

- Model path: `model/best.pt`
- Classes: `raw`, `ripe`,`rotten`
- Trained using YOLOv8

## 🧪 Running the Detection

Open and run the notebook: `deploy.ipynb`.

Make sure:
- Your ESP32 is connected and accessible via a COM port
- The trained model path is correctly set
- Your webcam is connected

## 🔌 ESP32 Firmware

Check the `esp32/esp32_sorter.ino` file for the microcontroller code that handles conveyor and sorting motor control.

## 🧰 Setup

Install Python dependencies:

```bash
pip install -r requirements.txt
```

Upload ESP32 code using Arduino IDE or PlatformIO.

## 📄 License

MIT License

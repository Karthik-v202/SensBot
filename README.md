
# 🚨 SensBot: Wi-Fi Controlled Environmental Monitoring Robot

SensBot is a remotely operated vehicle (ROV) designed for real-time environmental monitoring in hazardous or hard-to-reach areas. Equipped with sensors to measure temperature, humidity, and flammable gas levels, SensBot is controlled via a custom Wi-Fi-based controller interface. It’s ideal for use in safety inspection, disaster zones, laboratories, and educational demonstrations.




## 📸 Project Showcase

![SensBot - Environmental Sensing Robot](https://karthik-v202.github.io/SensBot/IMG_20250710_101532.jpg)

![SensBot - Environmental Sensing Robot](https://karthik-v202.github.io/SensBot/Screenshot%202025-09-30%20203230.png)

![SensBot - Environmental Sensing Robot](https://karthik-v202.github.io/SensBot/SensBot%20explode%20view.gif)

![Blynk - Control Surface web](https://karthik-v202.github.io/SensBot/Screenshot%202025-07-10%20101821.png)

![Blynk - Control Surface mobile](https://karthik-v202.github.io/SensBot/Screenshot_2025-07-10-10-16-25-904_cloud.blynk-edit.png)






## 🔧 Features

- 📡 Wi-Fi Remote Control – Real-time wireless control of the bot using a dedicated controller.
- 🌡️ Temperature Sensor – Measures ambient temperature.
- 💧 Humidity Sensor – Tracks relative humidity in the environment. 
- 🔥 Gas Sensor (MQ Series) – Detects presence of flammable or hazardous gases.
- 🛞 Mobile Base – Chassis with motor drivers for smooth movement.
- ⚡ Battery Powered – Fully portable and rechargeable.




## 🧠 Tech Stack & Components


**🧲 Microcontroller**: ESP8266 / NodeMCU

**📶 Connectivity**: Wi-Fi

**🔍 Sensors**: DHT11/DHT22 for Temperature & Humidity, 
     MQ-2/MQ-135 for Flammable Gas Detection

**🎮 Controller**: Blynk app with joystick, buttons, and ESP8266

**🔋 Power Supply**: Li-ion Battery Pack

**🔧 Chassis**: 4WD Robot Platform




## 🛠️ How It Works
 1. Connect the Bot and Controller via Wi-Fi
 2. Control Movement using joystick/buttons
 3. Sensor Data is transmitted live to the controller/display
 4. Data Logging or Alerting possible in advanced versions

## 🚀 Getting Started
Requirements

- Arduino IDE or PlatformIO

- Libraries: DHT11, MQ9, ESP8266 WiFi

Uploading Code
- Clone the repo

- Copy config_template.h to config.h in the project root.
- Open config.h and fill in your Wi-Fi SSID, password, and Blynk credentials (token, template ID, device name).
- **Do not commit your real credentials to the repository.**

- Connect ESP8266 via USB

- Select board & COM port

- Upload bot code and configure the controller app 
## 📦 Future Improvements
- Add camera module for live video streaming
- Integrate cloud data logging (Firebase / MQTT)
- Add obstacle detection (ultrasonic / IR)
- Build web dashboard for remote access
- Solar charging module
- Add more sensors like MQx, GPS etc
- Add another communication like LoRa, etc
## 📜 License
This project is open-source under the MIT License. 
[MIT](https://choosealicense.com/licenses/mit/)


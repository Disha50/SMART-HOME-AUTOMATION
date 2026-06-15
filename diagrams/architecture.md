# 🏗️ System Architecture
```mermaid graph LR User["👤 User"] -->|Voice Command| Alexa["🗣️ Amazon Alexa"] Alexa -->|Cloud Request| Sinric["☁️ Sinric Pro Cloud"] Sinric -->|Wi-Fi| ESP32["📡 ESP32 / NodeMCU"] ESP32 --> Relay["🔌 Relay Module"] Relay --> Light["💡 Light"] Relay --> Fan["🌀 Fan"] Relay --> Charger["🔋 Mobile Charger"] ```
## Description
The user gives voice commands to Amazon Alexa, which sends the request to the Sinric Pro cloud. The ESP32 receives the command through Wi-Fi and activates the appropriate relay to control connected appliances.

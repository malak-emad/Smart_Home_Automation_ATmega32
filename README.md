# Smart Home Automation Using ATmega32

This project showcases a **Smart Home Automation** system that controls lighting, fan speed, and fire detection using the ATmega32 microcontroller. The system reacts to environmental data such as light intensity, temperature, and flame detection, and displays information on an LCD screen.

## Features:
- **Automatic Lighting Control**: Uses an LDR sensor to control three LEDs based on ambient light intensity.
- **Temperature-Based Fan Control**: Adjusts fan speed using PWM according to temperature readings from the LM35 sensor.
- **Fire Detection**: The flame sensor triggers a buzzer and displays a warning on the LCD when fire is detected.
- **LCD Display**: Shows real-time temperature, light intensity, and system status.

## Hardware Components:
- **ATmega32 Microcontroller**
- **LDR Sensor**: Connected to ADC to measure light intensity.
- **LM35 Temperature Sensor**: Used for temperature monitoring.
- **Flame Sensor**: Detects fire and triggers alerts.
- **PWM-Controlled Fan Motor**: Speed adjusted based on temperature.
- **16x2 LCD Display**: Shows system status and sensor readings.
- **LEDs**: Indicate light intensity levels.
- **Buzzer**: Alerts in case of fire.

## How It Works:
1. The system monitors light intensity, temperature, and fire using respective sensors.
2. LEDs adjust according to light levels, fan speed adjusts based on temperature, and the flame sensor alerts in case of fire.
3. Real-time sensor data and system status are shown on the LCD.

Explore the full code and circuit design [here](Link).

## Acknowledgments:
Special thanks to **Eng. Mohamed Tarek** for guidance during the project.

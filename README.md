# TrafficLight-Control-System
This is a simple yet intelligent traffic light system implemented using an Arduino Uno. The system utilizes IR sensors to detect vehicles and dynamically adjust traffic light signals. Additionally, an LDR (Light Dependent Resistor) is used to control ambient street lighting based on the surrounding light conditions.

## Features
- **Traffic Light Control**: Automatically manages traffic signals based on vehicle detection.
- **IR Sensors**: Detects vehicles at four different roads and optimizes signal timing.
- **LDR-Based Street Lighting**: Automatically turns street lights on or off depending on ambient light conditions.
- **Serial Monitoring**: Outputs sensor data to the serial monitor for debugging and analysis.

## Hardware Requirements
- Arduino Uno Board
- LEDs Traffic Module (Red, Yellow, Green)
- IR Sensors (4 units)
- LDR Sensor (Light Dependent Resistor)
- Resistors (if required)
- Jumper Wires
- Breadboard

## Pin Configuration
| Component   | Arduino Pin |
|------------|------------|
| Traffic Light 1 (Red, Yellow, Green) | 2, 3, 4 |
| Traffic Light 2 (Red, Yellow, Green) | 5, 6, 7 |
| Traffic Light 3 (Red, Yellow, Green) | 8, 9, 10 |
| Traffic Light 4 (Red, Yellow, Green) | 11, 12, 13 |
| IR Sensor 1 | A0 |
| IR Sensor 2 | A1 |
| IR Sensor 3 | A2 |
| IR Sensor 4 | A3 |
| LDR Sensor | A4 |
| LED Control | A5 |

## Installation & Usage
1. Clone this repository.
2. Open the code in the Arduino IDE.
3. Connect the hardware components as per the pin configuration.
4. Upload the code to your Arduino board.
5. Monitor the system via the serial monitor.

## How It Works and Explanation of the Code

1. This system uses IR sensors to detect vehicles at intersections and dynamically control traffic lights, while also adjusting street lighting based on ambient light levels.
2. Vehicle Detection: The system reads values from the IR sensors connected to analog pins (A0 to A3) to detect the presence of vehicles. If a vehicle is detected on roads 1 or 3, those roads will receive a green light for 15 seconds, while roads 2 and 4 stay red. Similarly, if vehicles are detected on roads 2 or 4, those roads will get a green light, and roads 1 and 3 will turn red.
3. Normal Traffic Cycle: If no vehicles are detected on any road, the system follows a default traffic light cycle. In this cycle, each road gets a green light for 5 seconds, followed by a yellow light, and then red.
4. Street Lighting Control: The system reads the ambient light level using the LDR sensor connected to pin A4. If the ambient light is low (indicating nighttime), the system turns on the street lights. If the light is high (indicating daytime), the street lights remain off.
5. Looping Operation: The entire process runs in a loop, continuously checking sensor values and adjusting the traffic lights and street lights in real time based on the detected conditions. The system optimizes traffic flow and ensures efficient street lighting management.
6. In the code, the IR sensor readings are taken using analogRead(), and the traffic lights are controlled using digitalWrite() based on the sensor input. The LDR functionality is also controlled in the same way, turning street lights on/off depending on the ambient light readings.
       
## Contribution
Feel free to fork this repository, make improvements, and submit pull requests. Suggestions and contributions are always welcome!

## License
This project is licensed under the MIT License. You are free to use, modify, and distribute the code, as long as you include the original copyright and license notice in any copies of the code.

This project helps manage traffic dynamically and efficiently based on real-time conditions.


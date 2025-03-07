# TrafficLight-Control-System
This is a simple yet intelligent traffic light system implemented using an Arduino. The system utilizes IR sensors to detect vehicles and dynamically adjust traffic light signals. Additionally, an LDR (Light Dependent Resistor) is used to control ambient street lighting based on the surrounding light conditions.

## Features
- **Traffic Light Control**: Automatically manages traffic signals based on vehicle detection.
- **IR Sensors**: Detects vehicles at four different roads and optimizes signal timing.
- **LDR-Based Street Lighting**: Automatically turns street lights on or off depending on ambient light conditions.
- **Serial Monitoring**: Outputs sensor data to the serial monitor for debugging and analysis.

## Hardware Requirements
- Arduino Board
- LEDs (Red, Yellow, Green for each traffic signal)
- IR Sensors (4 units)
- LDR Sensor (Light Dependent Resistor)
- Resistors (as required)
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
1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/your-repository.git
   ```
2. Open the code in the Arduino IDE.
3. Connect the hardware components as per the pin configuration.
4. Upload the code to your Arduino board.
5. Monitor the system via the serial monitor.

## How It Works
1. The system reads values from IR sensors to determine the presence of vehicles at intersections.
2. If a vehicle is detected on roads 1 or 3, those roads get a green signal while roads 2 and 4 get a red signal.
3. Similarly, if a vehicle is detected on roads 2 or 4, those roads get a green signal while roads 1 and 3 get a red signal.
4. If no vehicles are detected, the system follows a normal traffic light cycle.
5. The LDR sensor detects the ambient light level and turns on/off the street lighting accordingly.
6. The entire process runs in a loop, ensuring real-time traffic management.

## Contribution
Feel free to fork this repository, make improvements, and submit pull requests. Suggestions and contributions are always welcome!

## License
This project is proprietary and all rights are reserved. Please contact the author for permission before using, modifying, or distributing this code.

---

### Explanation of the Code
The code implements a traffic light system using IR sensors and an LDR. Here's how it works:

- **Traffic Light Control**: The IR sensors check if vehicles are present at specific roads. If a vehicle is detected on roads 1 or 3, those lights turn green for 15 seconds while the other roads stay red. If a vehicle is detected on roads 2 or 4, those roads turn green for 15 seconds while the others turn red.
- **Normal Sequence**: If no vehicles are detected, a default cycle runs, where each road gets a green light for 5 seconds, followed by a yellow signal, and then red.
- **LDR Functionality**: The system reads the LDR sensor and turns on the street lighting when it's dark.

Overall, this project helps manage traffic dynamically and efficiently based on real-time conditions!


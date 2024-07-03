# Sensory-Stick-A-Smart-IoT-Solution-For-Blind-Navigation

## Project OverView
* There are so many blind people in the society, who is suffering from exercising the basic things of daily life and that could put lives at risk while travelling. There is a necessity these days to provide security and safety to blind people. There have been few devices developed so far to help the blind people. The blind stick is integrated with Multiple sensor to update to detect the person environment condition and send alert message to family members.
* In this proposed system, we have designed a Innovative Blind stick using Arduino as main Microcontroller board, and using multiple sensor such as Moisture, Ultrasonic Sensor we have designed a smart blind stick. Project working steps are as follows.
    1. Three Ultrasonic Sensor is used to detect in three direction (Left, Right and 
Front) and if the Distance is less than threshold value than it will generate a 
Voice message through speaker 
    2. If user press Emergency Switch, than a Buzzer alert will be generated and SMS 
of location will be send to the Family Members
    3. Temperature and Humidity sensor data are interfaced with Nodemcu IoT 
module to send the Environment condition data on Blynk based Cloud Server.
    4. If moisture is detected by the Sensor, than it will generate a Voice output 
message. 
- For IoT based data upload, Blynk based cloud server is used and user can view this data 
from anywhere in the world using Blynk Application.
- The power supply setup of the system contains a 12V Battery, Voltage Regulators, Filter Capacitors and Charging Circuit. 12V Output form 7812 Voltage regulator and 5V Output from Voltage regulators is used to power Microcontroller, Accelerometer and Ultrasonic Sensor. Filter capacitor are used to remove ripples from DC Voltage. Charging Circuit along with 12V adapter is used to charge the 12V battery

## Team Members
- [Niharika Bandila](https://github.com/niharikabandila)
- [Harshit Kumar](https://github.com/Harshit-singh1234)
- [Nikhil Pasupuleti](https://github.com/Nikhiljhonny)
- [Amrutha Varshini Yadla](https://github.com/amrutha453)

## Requirements
### NON-FUNCTIONAL REQUIREMENTS
#### SOFTWARE REQUIREMENTS
  - Arduino IDE Compiler 
  -  Embedded C Programming Language
#### HARDWARE REQUIREMENTS
  -  Arduino UNO – Atmega 328 
  - 12V Battery 
  - GPS Module 
  - GSM Module 
  - Ultrasonic Sensor 
  - Voice Module 
  - Switches 
  - Temperature and Humidity Sensor 
  - NodeMCU 
  - Buzzer Module 
  - Voltage Regulators 
  - Filter Capacitors 
  - Walking Stick 
  - Other Misc Components
### FUNCTIONAL REQUIREMENTS
  - Performance : Ensure efficient obstacle detection, response time, GPS accuracy and battery life.
  - Usability : This system having audio alert clarity, volume control and also weight and balance.
  - Reliability : It ensures system uptime, sensor accuracy and GSM connectivity.
  - Security : Data Privacy should be ensured during the process.
  - Maintainability : The system is designed for ease of repair and software updates.
  - Environmental Factors : The system should function reliably in different weather conditions (e.g., rain, extreme temperatures).
  - Cost Effective : The overall cost of the system (including components and maintenance) should be affordable for the target user group
## RESULTS AND DISCUSSIONS
- Object Detection : Objects may be present on the lower surface in the route of the blind or high level objects in front of him. A variety of objects at varying distances and heights are placed, and later the sensor is linked to oscilloscope to know the received signal variation. We get result as no signal, If there is no obstacle on the lower surface or in front of sensor. The environmental noise show on the oscilloscope as a very weak signal as shown in above Fig. If an obstacle present in front of sensor a obtained signal by sensor with amplitude greater than that received signal by disposed sensor.
- Voice feedback upon obstacle detection : We also checked the voice notification using the voice playback warning module and it is able to provide the correct instruction to the user through speaker.
-  Location finding and Emergency Unit : The emergency button used in the smart walking stick to send the location message to the preset contact number. To make GSM to be trigger the microcontroller has to detect the interrupt for once. Sequences of 20 tests were performed, 60% of all SMS was sent within one minute. 70% of SMS was sent under 2 minutes and 80% of the messages were sent within 3 minutes. Finally 90% of the messages were sent within 4 minutes and the remaining are failed to send an SMS after 5 minutes.
- Blynk Server :  And we can also see the Temperature and Humidity data in the blynk server app.







# ESP32 Web Server Control
This project demonstrates controlling LEDs connected to an ESP32 microcontroller via a web server. Users can interact with the web interface to turn individual LEDs on and off.

### Prerequisites
- ESP32 microcontroller board
- LEDs (connected to appropriate GPIO pins)
- WiFi network

### Getting Started
- Connect the LEDs to the GPIO pins of the ESP32 board as specified in the code.
- Modify the ssid and password variables in the code to match your WiFi network credentials.
- Upload the code to your ESP32 board using the Arduino IDE or any other suitable development environment.
- Open the serial monitor to view the ESP32's IP address once it's connected to the WiFi network.
- Access the IP address in a web browser to interact with the web interface.
  
### Usage
- The web interface provides buttons to control each LED individually.
- Clicking the "ON" button turns the respective LED on, and clicking the "OFF" button turns it off.
- Each LED corresponds to a specific URL endpoint, such as /0/on or /0/off.
- The state of each LED is reflected in the web interface.
- The code handles incoming HTTP requests and updates the LED states accordingly.

### Files Included
- web_server_led_control.ino: Arduino sketch containing the code for the ESP32 microcontroller.

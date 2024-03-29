#include <WiFi.h>

const char* ssid = "TF";
const char* password = "rtvr2860";

WiFiServer server(80);

String header;

//variable to store the current LED states
String no0 = "off";
String no1 = "off";
String no2 = "off";
String no3 = "off";
String no4 = "off";
String no5 = "off";
String no6 = "off";
String no7 = "off";
String no8 = "off";
String no9 = "off";

const int ledPin5 = 5;
const int ledPin18 = 18;
const int ledPin22 = 22;
const int ledPin21 = 21;
const int ledPin19 = 19;
const int ledPin4 = 4;
const int ledPin23 = 23;

unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds
const long timeoutTime = 2000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(ledPin5,OUTPUT);
  digitalWrite(ledPin5,0);

  pinMode(ledPin18,OUTPUT);
  digitalWrite(ledPin18,0);

  pinMode(ledPin22,OUTPUT);
  digitalWrite(ledPin22,0);
  
  pinMode(ledPin21,OUTPUT);
  digitalWrite(ledPin21,0);
  
  pinMode(ledPin19,OUTPUT);
  digitalWrite(ledPin19,0);
  
  pinMode(ledPin4,OUTPUT);
  digitalWrite(ledPin4,0);
  
  pinMode(ledPin23,OUTPUT);
  digitalWrite(ledPin23,0);
  
  delay(10);

    // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
    
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
   WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";

    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            if (header.indexOf("GET /0/on") >= 0) {
              no0 = "on";
              digitalWrite(5,0);//a
              digitalWrite(18,0);//b
              digitalWrite(22,0);//c
              digitalWrite(21,0);//d
              digitalWrite(19,0);//e
              digitalWrite(4,0);//f
              digitalWrite(23,1);//g
            }else if (header.indexOf("GET /0/off") >= 0) {
              no0 = "off";
              digitalWrite(5,1);//a
              digitalWrite(18,1);//b
              digitalWrite(22,1);//c
              digitalWrite(21,1);//d
              digitalWrite(19,1);//e
              digitalWrite(4,1);//f
              digitalWrite(23,1);//g              //turns the LED off
            }

            if (header.indexOf("GET /1/on") >= 0) {
              no1 = "on";
              digitalWrite(5,1);//a
              digitalWrite(18,0);//b
              digitalWrite(22,0);//c
              digitalWrite(21,1);//d
              digitalWrite(19,1);//e
              digitalWrite(4,1);//f
              digitalWrite(23,1);//g
            }else if (header.indexOf("GET /1/off") >= 0) {
              no1 = "off";
              digitalWrite(5,1);//a
              digitalWrite(18,1);//b
              digitalWrite(22,1);//c
              digitalWrite(21,1);//d
              digitalWrite(19,1);//e
              digitalWrite(4,1);//f
              digitalWrite(23,1);//g              //turns the LED off
            }

            if (header.indexOf("GET /2/on") >= 0) {
              no2 = "on";
              digitalWrite(5,0);//a
              digitalWrite(18,0);//b
              digitalWrite(22,1);//c
              digitalWrite(21,0);//d
              digitalWrite(19,0);//e
              digitalWrite(4,1);//f
              digitalWrite(23,0);//g
            }else if (header.indexOf("GET /2/off") >= 0) {
              no2 = "off";
              digitalWrite(5,1);//a
              digitalWrite(18,1);//b
              digitalWrite(22,1);//c
              digitalWrite(21,1);//d
              digitalWrite(19,1);//e
              digitalWrite(4,1);//f
              digitalWrite(23,1);//g              //turns the LED off
            }

            if (header.indexOf("GET /3/on") >= 0) {
              no3 = "on";
              digitalWrite(5,0);//a
              digitalWrite(18,0);//b
              digitalWrite(22,0);//c
              digitalWrite(21,0);//d
              digitalWrite(19,1);//e
              digitalWrite(4,1);//f
              digitalWrite(23,0);//g
            }else if (header.indexOf("GET /3/off") >= 0) {
              no3 = "off";
              digitalWrite(5,1);//a
              digitalWrite(18,1);//b
              digitalWrite(22,1);//c
              digitalWrite(21,1);//d
              digitalWrite(19,1);//e
              digitalWrite(4,1);//f
              digitalWrite(23,1);//g              //turns the LED off
            }

            if (header.indexOf("GET /4/on") >= 0) {
              no4 = "on";
              digitalWrite(5,1);//a
              digitalWrite(18,0);//b
              digitalWrite(22,0);//c
              digitalWrite(21,1);//d
              digitalWrite(19,1);//e
              digitalWrite(4,0);//f
              digitalWrite(23,0);//g
            }else if (header.indexOf("GET /4/off") >= 0) {
              no4 = "off";
              digitalWrite(5,1);//a
              digitalWrite(18,1);//b
              digitalWrite(22,1);//c
              digitalWrite(21,1);//d
              digitalWrite(19,1);//e
              digitalWrite(4,1);//f
              digitalWrite(23,1);//g              //turns the LED off
            }

            if (header.indexOf("GET /5/on") >= 0) {
              no5 = "on";
              digitalWrite(5,0);//a
              digitalWrite(18,1);//b
              digitalWrite(22,0);//c
              digitalWrite(21,0);//d
              digitalWrite(19,1);//e
              digitalWrite(4,0);//f
              digitalWrite(23,0);//g
            }else if (header.indexOf("GET /5/off") >= 0) {
              no5 = "off";
              digitalWrite(5,1);//a
              digitalWrite(18,1);//b
              digitalWrite(22,1);//c
              digitalWrite(21,1);//d
              digitalWrite(19,1);//e
              digitalWrite(4,1);//f
              digitalWrite(23,1);//g              //turns the LED off
            }

            if (header.indexOf("GET /6/on") >= 0) {
              no6 = "on";
              digitalWrite(5,0);//a
              digitalWrite(18,1);//b
              digitalWrite(22,0);//c
              digitalWrite(21,0);//d
              digitalWrite(19,0);//e
              digitalWrite(4,0);//f
              digitalWrite(23,0);//g
            }else if (header.indexOf("GET /6/off") >= 0) {
              no6 = "off";
              digitalWrite(5,1);//a
              digitalWrite(18,1);//b
              digitalWrite(22,1);//c
              digitalWrite(21,1);//d
              digitalWrite(19,1);//e
              digitalWrite(4,1);//f
              digitalWrite(23,1);//g              //turns the LED off
            }

            if (header.indexOf("GET /7/on") >= 0) {
              no7 = "off";
              digitalWrite(5,0);//a
              digitalWrite(18,0);//b
              digitalWrite(22,0);//c
              digitalWrite(21,1);//d
              digitalWrite(19,1);//e
              digitalWrite(4,1);//f
              digitalWrite(23,1);//g
            }else if (header.indexOf("GET /7/off") >= 0) {
              no7 = "off";
              digitalWrite(5,1);//a
              digitalWrite(18,1);//b
              digitalWrite(22,1);//c
              digitalWrite(21,1);//d
              digitalWrite(19,1);//e
              digitalWrite(4,1);//f
              digitalWrite(23,1);//g              //turns the LED off
            }

            if (header.indexOf("GET /8/on") >= 0) {
              no8 = "on";
              digitalWrite(5,0);//a
              digitalWrite(18,0);//b
              digitalWrite(22,0);//c
              digitalWrite(21,0);//d
              digitalWrite(19,0);//e
              digitalWrite(4,0);//f
              digitalWrite(23,0);//g
            }else if (header.indexOf("GET /8/off") >= 0) {
              no8 = "off";
              digitalWrite(5,1);//a
              digitalWrite(18,1);//b
              digitalWrite(22,1);//c
              digitalWrite(21,1);//d
              digitalWrite(19,1);//e
              digitalWrite(4,1);//f
              digitalWrite(23,1);//g              //turns the LED off
            }

            if (header.indexOf("GET /9/on") >= 0) {
              no9 = "on";
              digitalWrite(5,0);//a
              digitalWrite(18,0);//b
              digitalWrite(22,0);//c
              digitalWrite(21,0);//d
              digitalWrite(19,1);//e
              digitalWrite(4,0);//f
              digitalWrite(23,0);//g
            }else if (header.indexOf("GET /9/off") >= 0) {
              no9 = "off";
              digitalWrite(5,1);//a
              digitalWrite(18,1);//b
              digitalWrite(22,1);//c
              digitalWrite(21,1);//d
              digitalWrite(19,1);//e
              digitalWrite(4,1);//f
              digitalWrite(23,1);//g              //turns the LED off
            }

          client.println("<!DOCTYPE html>");
          client.println("<html>");
          client.println("<head>");
          client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
          client.println("<style>");
          client.println("body { font-family: Arial, sans-serif; margin: 0; padding: 0;}");
          client.println(".container { text-align: center; margin-top: 50px;}");
          client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 15px 32px;");
          client.println("text-align: center; text-decoration: none; display: inline-block; font-size: 16px;");
          client.println("margin: 4px 2px; cursor: pointer;}");
          client.println(".button.off { background-color: #f44336; }");
          client.println("</style>");
          client.println("</head>");
          client.println("<body>");

          client.println("<div class=\"container\">");
          client.println("<h1>ESP32 Web Server</h1>");
          client.println("<p>Control LED State</p>");

          // Function to generate button HTML for each LED
          auto generateButton = [&](int led, const String& state) {
              client.print("<p><a href=\"/");
              client.print(led);
              client.print(state == "off" ? "/on\"" : "/off\"");
              client.print("><button class=\"button");
              client.print(state == "off" ? "" : " off");
              client.print("\">");
              client.print("Click to ");
              client.print(state == "off" ? "On" : "Off");
              client.println(" LED ");
              client.print(led);
              client.println("</button></a></p>");
          };

          // Generate buttons for LEDs 0 to 9
          for (int i = 0; i < 10; ++i) {
              generateButton(i, "off"); // Default state is off
          }

          client.println("</div>");
          client.println("</body>");
          client.println("</html>");


            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}

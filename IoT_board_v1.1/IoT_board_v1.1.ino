// Import required libraries
#include <FS.h>
#include <LittleFS.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>


#define ledPin 13 // GPIO pin to use as the output

#define relay1Pin 16
#define relay2Pin 14
#define relay3Pin 12

// Replace with your network credentials
const char* ssid = "************"; //Replace with your own SSID
const char* password = "************"; //Replace with your own password

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
 
void setup(){

  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);

  // Initialize LittleFS
  if(!LittleFS.begin()){
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting to WiFi..");
    blink_led(250);
  }

  // wifi successfully connected
  digitalWrite(ledPin, HIGH);

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/index.html");
  });
  
  // Route to load style.css file
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/style.css", "text/css");
  });

  // Route to load script.js file
  server.on("/jquery-3.7.0.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/jquery-3.7.0.js", "application/javascript");
  });

  // Route to load image.png file
  server.on("/logo.png", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(LittleFS, "/logo.png", "image/png");
  });

  // Route to set GPIO to HIGH
  server.on("/bulb-true", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(relay1Pin, HIGH);    
    //request->send(LittleFS, "/index.html");
  });
  
  // Route to set GPIO to LOW
  server.on("/bulb-false", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(relay1Pin, LOW);    
    //request->send(LittleFS, "/index.html");
  });

  // Route to set GPIO to HIGH
  server.on("/ac-true", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(relay2Pin, HIGH);    
    //request->send(LittleFS, "/index.html");
  });
  
  // Route to set GPIO to LOW
  server.on("/ac-false", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(relay2Pin, LOW);    
    //request->send(LittleFS, "/index.html");
  });

  // Route to set GPIO to HIGH
  server.on("/light-true", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(relay3Pin, HIGH);    
    //request->send(LittleFS, "/index.html");
  });
  
  // Route to set GPIO to LOW
  server.on("/light-false", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(relay3Pin, LOW);    
    //request->send(LittleFS, "/index.html");
  });

  // Start server
  server.begin();
}
 
void loop(){
  
}

void blink_led(uint8_t cycle)
{
    Serial.print("cycle: ");
    Serial.println(cycle);
    
    digitalWrite(ledPin, HIGH);
    delay(cycle);
    digitalWrite(ledPin, LOW);
    delay(cycle);
}
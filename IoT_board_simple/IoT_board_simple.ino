// Import required libraries
#include <FS.h>
#include <LittleFS.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char* ssid = ""; //Replace with your own SSID
const char* password = ""; //Replace with your own password

const int relay1Pin = 16;
const int relay2Pin = 14;
const int relay3Pin = 12;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
 
void setup(){

  Serial.begin(115200);
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
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

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

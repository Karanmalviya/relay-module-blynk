#define BLYNK_TEMPLATE_ID "TMPLmE7HhM6P"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "Z4wAZUj3LNBcZb2fjs23mxiyid66_W5p"


#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "hotspot";
char pass[] = "12345678";



// This function is called every time the Virtual Pin 0 state changes

BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  Serial.println(value);

  if(value == 1){
    Serial.println("ON");
    digitalWrite(D1, HIGH);
  }
  else{
    Serial.println("OFF");
    digitalWrite(D1, LOW);
  }

  
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(D1, OUTPUT);
}

void loop()
{
  Blynk.run();
  
}
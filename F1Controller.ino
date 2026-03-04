#include "WifiSettings.h"
#include "Relogio.h"

  const char* ntpServer = "a.st1.ntp.br";
  const long  gmtOffset_sec = -3 * 3600;
  const int   daylightOffset_sec = 0;

void setup() {
  Serial.begin(115200);
  
  while (!Serial) { 
    delay(10); 
  }
  
  delay(1000);
  Serial.println("Ligando...");
  configuraWifi(); //Configura WiFi ao ligar

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer); //Configura horário ao ligar

}

void loop() {
  delay(1000);
  
}

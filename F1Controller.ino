#include "WifiSettings.h"
#include "DadosF1.h"
#include "LedController.h"

  //Time control
  const char* ntpServer = "a.st1.ntp.br";
  const long  gmtOffset_sec = -3 * 3600;
  const int   daylightOffset_sec = 0;

  //Data time control
  unsigned long lastExecution = 0;
  unsigned long currentInterval = 10000;

  //Test
  char test = ' ';

void setup() {
  Serial.begin(115200);
  
  while (!Serial) { 
    delay(10); 
  }
  
  delay(1000);
  Serial.println("Ligando...");
  configWifi(); //Configura WiFi ao ligar

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer); //Configura horário ao ligar

}

void loop() {
  

  unsigned long now = millis();
  

  if(WiFi.status() == WL_CONNECTED){
      bool active = getStatus();

      if(Serial.available() > 0){
        char c = Serial.read();
      
      if (c != '\n' && c != '\r') {
        test = c; 
        Serial.print("Comando de teste recebido: ");
        Serial.println(test);
      }

        /*
          Type in the Serial Monitor the letters and receive a return about the race status
          Y = Yellow Flag
          R = Red Flag
          S = Safety Car

        */
      }

  if(now - lastExecution >= currentInterval){
    lastExecution = now;

    

      currentInterval = active ? 3000 : 10000;

      String currentFlag = fetchRaceControlFlags();
      updateLedsF1(currentFlag, active, test);

      Serial.printf("Status: %s | Bandeira: %s\n", 
                    active ? "CORRIDA" : "OFF", currentFlag.c_str());

      test = ' ';
      
  }

  }
  
}

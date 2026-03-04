#include <time.h>

  

void printHora(){

  struct tm timeInfo;
  if(!getLocalTime(&timeInfo)){
    Serial.println("Falha ao obter tempo");
    return;
  }
  Serial.println(&timeInfo,"%A, %B %d %Y %H:%M:%S");

}
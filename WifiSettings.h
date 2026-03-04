#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>

void configuraWifi(){

  WiFiManager wifiManager;

  wifiManager.setConfigPortalTimeout(240);

  if(!wifiManager.autoConnect("ControladorF1", "configuracao")){
    Serial.println("Falha na conexao. Resetar e tentar novamente...");
    delay(3000);
    ESP.restart();
    delay(5000);
  }

  Serial.println("Conectado a rede WIFI");

}
#include <HTTPClient.h>
#include <NetworkClientSecure.h>

const char* raceControlUrl = "https://f1-led-bridge.onrender.com/status";

// Cria uma estrutura para retornar os dois valores juntos
struct RaceData {
  bool active;
  String flag;
};

RaceData fetchRaceData() {
  RaceData data;
  data.active = false;
  data.flag = "OFFLINE";

  NetworkClientSecure client;
  client.setInsecure();
  HTTPClient http;

  http.begin(client, raceControlUrl);
  http.setReuse(true);
  
  int httpCode = http.GET();

  if (httpCode == 200) {
    data.active = true;
    data.flag = http.getString();
    data.flag.trim(); 
  } else {
    Serial.printf("Falha na conexão: %d\n", httpCode);
  }
  
  http.end();
  return data;
}
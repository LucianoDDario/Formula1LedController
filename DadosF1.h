#include <HTTPClient.h>
#include <ArduinoJson.h>

  const char* sessionURL = "https://api.openf1.org/v1/sessions?date_end=null";
  const char* raceControlUrl = "https://api.openf1.org/v1/race_control?session_key=latest";

  bool getStatus(){

    HTTPClient http;
    http.begin(sessionURL);
    int httpCode = http.GET();

    bool active = false;
    if(httpCode == 200){
      String payload = http.getString();
        if(payload.length() > 2){
          active = true;
        }
    }
    http.end();

    return active;
  }

  String fetchRaceControlFlags(){

    HTTPClient http;
    http.begin(raceControlUrl);
    int httpCode = http.GET();

    if(httpCode == 200){

      String payload = http.getString();
      DynamicJsonDocument doc(2048);
      DeserializationError error = deserializeJson(doc, payload);

        if(!error){

          JsonArray array = doc.as<JsonArray>();

          if(array.size() > 0){

            JsonObject lastEvent = array[array.size() - 1];

          if(lastEvent.containsKey("flag") && !lastEvent["flag"].isNull()){

            return lastEvent["flag"].as<String>();   

            

          }
        }
      }

    }else {
    Serial.printf("Falha na conexão: %d\n", httpCode);
  }
  http.end();
  return "Clear";
  }
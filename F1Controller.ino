#include "WifiSettings.h"
#include "DadosF1.h"
#include "LedController.h"

// Time control
const char* ntpServer = "a.st1.ntp.br";
const long gmtOffset_sec = -3 * 3600;
const int daylightOffset_sec = 0;

// Data time control
unsigned long lastExecution = 0;
unsigned long currentInterval = 10000;

// Test
char test = ' ';

void setup() {
  Serial.begin(115200);

  while (!Serial) {
    delay(10);
  }

  delay(1000);
  Serial.println("Ligando...");
  configWifi();  // Configura WiFi ao ligar

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);  // Configura horário ao ligar
  setupLeds();
}

void loop() {
  unsigned long now = millis();
  float coreTemp = temperatureRead();
  uint32_t freeRAM = ESP.getFreeHeap();

  if (WiFi.status() == WL_CONNECTED) {

    // 1. LEITURA DO SERIAL E CONTROLE DO MODO DE TESTE
    if (Serial.available() > 0) {
      char c = Serial.read();
      if (c != '\n' && c != '\r') {
        if (c == 'p' || c == 'P') {
          test = ' ';  // A letra 'p' encerra o teste
          Serial.println("Teste encerrado. Retornando aos dados da API...");
          lastExecution = now - currentInterval;  // Força uma requisição na API imediatamente
        } else {
          test = c;  // Armazena a letra para rodar em loop
          Serial.print("Modo de teste contínuo ativado: ");
          Serial.println(test);
        }
      }
    }

    // 2. SEPARAÇÃO: MODO TESTE VS MODO API
    if (test != ' ') {

      // Se estiver em teste, atualiza os LEDs continuamente (ignora a internet)
      updateLedsF1("", true, test);
      delay(50);  // Pausa pequena para não travar o ESP com excesso de velocidade no loop

    } else {

      // Se NÃO estiver em teste, usa o temporizador normal da API da F1
      if (now - lastExecution >= currentInterval) {
        lastExecution = now;

        Serial.print("[Hardware] Memória RAM livre: ");
        Serial.print(freeRAM / 1024);
        Serial.println(" KB");
        Serial.print("[Hardware] Temperatura do CPU: ");
        Serial.print(coreTemp);
        Serial.println(" °C");

        // Busca os dados oficiais
        RaceData raceData = fetchRaceData();  //
        currentInterval = raceData.active ? 3000 : 15000;

        updateLedsF1(raceData.flag, raceData.active, test);

        Serial.printf("Status: %s | Bandeira: %s\n",
                      raceData.active ? "CORRIDA" : "OFF", raceData.flag.c_str());
      }
    }
  }
}
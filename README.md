🏎️ F1 Race Control LED Indicator

This project uses an ESP32 (or compatible board) to monitor Formula 1 race conditions in real-time. It connects to a bridge API to fetch flag status (Yellow, Red, Safety Car, etc.) and displays corresponding lighting patterns on a WS2812B LED strip.

Este projeto utiliza um ESP32 (ou placa compatível) para monitorar as condições de uma corrida de Fórmula 1 em tempo real. Ele se conecta a uma API bridge para buscar o status das bandeiras (Amarela, Vermelha, Safety Car, etc.) e exibe padrões de iluminação correspondentes em uma fita de LED WS2812B.

🌟 Features / Funcionalidades
Real-time Sync: Automatically fetches data from a dedicated F1 status API.

Dynamic Visuals:

🟡 Safety Car / VSC: Flashing yellow followed by a "chase" light effect.

🔴 Red Flag: Solid red LEDs.

🟡 Yellow Flag: Solid yellow LEDs.

🟢 Idle/Active: Beautiful "Petronas Teal" color when no flags are active.

WiFi Manager: Easy setup via a captive portal—no need to hardcode your WiFi credentials.

Serial Test Mode: Send commands through the Serial Monitor to test animations instantly.

Hardware Monitoring: Tracks CPU temperature and free RAM.

Sincronização em Tempo Real: Busca dados automaticamente de uma API de status da F1.

Visuais Dinâmicos:

🟡 Safety Car / VSC: Pisca em amarelo seguido de um efeito de "rastro" giratório.

🔴 Bandeira Vermelha: LEDs em vermelho sólido.

🟡 Bandeira Amarela: LEDs em amarelo sólido.

🟢 Idle/Ativo: Cor "Petronas Teal" quando não há bandeiras ativas.

WiFi Manager: Configuração fácil via portal cativo (não precisa colocar a senha do WiFi no código).

Modo de Teste Serial: Envie comandos pelo Monitor Serial para testar as animações instantaneamente.

Monitoramento de Hardware: Monitora temperatura da CPU e memória RAM livre.

🛠️ Hardware Requirements / Requisitos de Hardware
Microcontroller: ESP32 (recommended).

LED Strip: WS2812B (30 LEDs configured by default).

Power Supply: 5V (adequate for the number of LEDs used).

Microcontrolador: ESP32 (recomendado).

Fita de LED: WS2812B (30 LEDs configurados por padrão).

Fonte de Alimentação: 5V (adequada para a quantidade de LEDs).

📂 Project Structure / Estrutura do Projeto
F1Controller.ino: Main logic, timing control, and Serial communication.

DadosF1.h: Handles HTTP requests to the race control API.

LedController.h: Contains all FastLED animations and color definitions.

WifiSettings.h: Manages the WiFi connection and the configuration portal.

🚀 Installation / Instalação
Install Libraries: You will need the following libraries in your Arduino IDE:

FastLED

WiFiManager (by tzapu)

Wiring:

Connect the Data Pin of the LED strip to GPIO 6 (change LED_PIN in LedController.h if necessary).

Upload: Upload the code to your ESP32.

WiFi Setup:

Connect your phone/PC to the WiFi network named "ControladorF1".

The password is "configuracao".

Configure your home WiFi in the portal that appears.

Instalar Bibliotecas: Você precisará das seguintes bibliotecas na Arduino IDE:

FastLED

WiFiManager (por tzapu)

Fiação:

Conecte o pino de dados da fita de LED ao GPIO 6 (altere LED_PIN em LedController.h se necessário).

Upload: Carregue o código para o seu ESP32.

Configuração WiFi:

Conecte seu celular/PC na rede WiFi chamada "ControladorF1".

A senha é "configuracao".

Configure o WiFi da sua casa no portal que aparecerá.

⌨️ Serial Commands / Comandos Serial
You can test the animations by typing these letters in the Serial Monitor (115200 baud):
Você pode testar as animações digitando estas letras no Monitor Serial:

s: Test Safety Car animation / Testar animação de Safety Car.

y: Test Yellow Flag / Testar Bandeira Amarela.

r: Test Red Flag / Testar Bandeira Vermelha.

p: Stop test and return to API data / Parar teste e voltar para os dados da API.

📝 License / Licença
This project is for educational and hobbyist purposes. Formula 1 is a trademark of Formula One Licensing BV.

Este projeto é para fins educacionais e de hobby. Formula 1 é uma marca registrada da Formula One Licensing BV.

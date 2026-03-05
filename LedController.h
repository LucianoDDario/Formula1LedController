#include <FastLED.h>

#define LED_PIN 5
#define NUM_LEDS 30

CRGB leds[NUM_LEDS];

const CRGB corPetronas = CRGB(0, 161, 155);

void setupLeds() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  FastLED.clear();
  FastLED.show();
}

void updateLedsF1(String flag, bool active, char test) {

  if(!active && test == ' '){
    fill_solid(leds, NUM_LEDS, corPetronas);
  }else{
    if (flag == "SAFETY CAR" || flag == "VSC" || test == 's') {
    //Piscar amarelo 2 vezes
    for(int j = 0; j < 2; j++) {
      fill_solid(leds, NUM_LEDS, CRGB::Yellow);
      FastLED.show();
      delay(200);
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      FastLED.show();
      delay(200);
    }

    //Circular a luz (Efeito de rastro/chase)
    for(int i = 0; i < NUM_LEDS; i++) {
      FastLED.clear();
      leds[i] = CRGB::Yellow;
      // Pequeno rastro atrás do LED principal
      if(i > 0) leds[i-1] = CRGB(150, 150, 0);
      if(i > 1) leds[i-2] = CRGB(50, 50, 0);
      
      FastLED.show();
      delay(30); // Velocidade do giro
      
    }

    Serial.println("Safety Car");
  }
    if (flag == "YELLOW" || test == 'y'){

      fill_solid(leds, NUM_LEDS, CRGB::Yellow);
      Serial.println("Yellow Flag");

    } 
    else if (flag == "RED" || test == 'r') {
      
      fill_solid(leds, NUM_LEDS, CRGB::Red);
      Serial.println("Red Flag");

    }
    else {
      
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      Serial.println("Clear");

    }
  }
  
  
  FastLED.show();
}
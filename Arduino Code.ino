#include "FastLED.h" /*Library needed*/

#define PIN 1 /*Your data pin here*/
#define NUM_LEDS 53 /*Amount of addressable RGB LEDs*/

CRGBArray<NUM_LEDS> leds;
uint8_t hue[NUM_LEDS];
void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);
  for (int i = 0; i < NUM_LEDS; i++) {
    hue[i] = 255 / NUM_LEDS * i;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue[i]++, 255, 255);
  }
FastLED.show();
delay(16); /* This number controls the speed of the RGB animation, you may tweak it however you like*/
}

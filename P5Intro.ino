#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN 5
#define NUMPIXELS 5

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500

int incomingByte;


void setup() {

  pixels.begin();
  for(int i = 0; i < NUMPIXELS; i++){
        pixels.setPixelColor(i, pixels.Color(50, 50, 0));
        pixels.show();
  }
  pixels.show();
  Serial.begin(9600);
  //pinMode(ledPin, OUTPUT);
}

void loop() {
  int pot = analogRead(A0);
  int slider = analogRead(A1);

if (Serial.available() > 0) { // if there's serial data available
    incomingByte = Serial.read();   // read it
    Serial.write(incomingByte);         // send it back out as raw binary data
    if(incomingByte == 0){
        for(int i = 0; i < NUMPIXELS; i++){
        pixels.setPixelColor(i, pixels.Color(50, 0, 0));
        pixels.show();
        }
    }
    if(incomingByte == 1){
      for(int i = 0; i < NUMPIXELS; i++){
        pixels.setPixelColor(i, pixels.Color(50, 50, 0));
        pixels.show();
        }
    }
    if(incomingByte == 2){
      for(int i = 0; i < NUMPIXELS; i++){
        pixels.setPixelColor(i, pixels.Color(0, 50, 0));
        pixels.show();
        }
    }
}

  Serial.print(pot);
  Serial.print(",");
  Serial.println(slider);
  delay(1); //allows the serial port to keep up
}

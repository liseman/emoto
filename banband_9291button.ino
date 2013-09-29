#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(3, PIN, NEO_GRB + NEO_KHZ800);

//button
const int buttonPin = 12;
int buttonState = 0;
int clickCount = 0;
//newpress determines if the button is being pressed for the first time (1) or held down (0)
boolean newPress = 1;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  //if button is pressed, change clickcount and set newpress to false
  if (buttonState == HIGH and newPress == 1)
  {
    clickCount++;
    newPress = 0;  
  }
  
  /*
  //if button is pressed and held, don't change
  if (buttonState == HIGH and newPress == 0)
  {
    clickCount++;
    newPress = 0;
  }
  */
  
  //if button is let go, set newPress to 1
  if (buttonState == LOW) newPress = 1;
  
  switch (clickCount)
  {
    case 1:
      work();
      break;
    case 2:
      conference();
      break;
    case 3:
      bar();
      break;
    case 4:
      folsom();
      break;
    case 5:
      off();
      clickCount = 0;
  }
  
  
  // Some example procedures showing how to display to the pixels:
  /*
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  delay(1000);
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  delay(1000);
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  delay(1000);
  */
  
  /*
  work();
  delay(1000);
  conference();
  delay(1000);
  bar();
  delay(1000);
  folsom();
  delay(1000);
  */
  
  /*
  strip.setPixelColor(1, 255, 0, 0);
  strip.show();
  delay(1000);
  strip.setPixelColor(1, 0, 0, 255);
  strip.show();
  */
//  rainbow(20);
//  rainbowCycle(20);
}

void work()
{
  //r/gdown/off
  strip.setPixelColor(0, 255, 0, 0);
  strip.setPixelColor(1, 0, 80, 0);
  strip.setPixelColor(2, 0, 0, 0);
  strip.show();
}

void conference()
{
  //y/g/b
  strip.setPixelColor(0, 255, 255, 0);
  strip.setPixelColor(1, 0, 255, 0);
  strip.setPixelColor(2, 0, 0, 255);
  strip.show();
}

void bar()
{
  //g/g/ydown
  strip.setPixelColor(0, 0, 255, 0);
  strip.setPixelColor(1, 0, 255, 0);
  strip.setPixelColor(2, 70, 70, 0);
  strip.show();
}

void folsom()
{
  //bo/ob/bo
  strip.setPixelColor(0, 255, 74, 0);
  strip.setPixelColor(1, 0, 0, 255);
  strip.setPixelColor(2, 255, 74, 0);
  strip.show();
  delay(100);
  strip.setPixelColor(0, 0, 0, 255);
  strip.setPixelColor(1, 255, 74, 0);
  strip.setPixelColor(2, 0, 0, 255);
  strip.show();
  delay(100);
}

void off()
{
  strip.setPixelColor(0, 0, 0, 0);
  strip.setPixelColor(1, 0, 0, 0);
  strip.setPixelColor(2, 0, 0, 0);
  strip.show();
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}


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

//buttons
const int buttonB = 12;
const int buttonA = 9;
const int buttonN = 10;

int buttonStateB = 0;
int clickCountB = 0;
int buttonStateA = 0;
int clickCountA = 0;
int buttonStateN = 0;
int clickCountN = 0;
//newpress determines if the button is being pressed for the first time (1) or held down (0)
boolean newPressB = 1;
boolean newPressA = 1;
boolean newPressN = 1;

boolean findMe = 0;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  pinMode(buttonB, INPUT);
  pinMode(buttonA, INPUT);
  pinMode(buttonN, INPUT);
}

void loop() {
  buttonStateB = digitalRead(buttonB);
  buttonStateA = digitalRead(buttonA);
  buttonStateN = digitalRead(buttonN);
  
  //if button is pressed, change clickcount and set newpress to false
  if (buttonStateB == HIGH and newPressB == 1)
  {
    clickCountB++;
    newPressB = 0;  
  }
  
  //if button is let go, set newPress to 1
  if (buttonStateB == LOW) newPressB = 1;
  
  switch (clickCountB)
  {
    case 1:
      strip.setPixelColor(0, 0, 255, 0);
      strip.show();
      break;
    case 2:
      strip.setPixelColor(0, 255, 255, 0);
      strip.show();
      break;
    case 3:
      strip.setPixelColor(0, 255, 0, 0);
      strip.show();
      break;
    case 4:
      strip.setPixelColor(0, 0, 0, 0);
      strip.show();
      clickCountB = 0;
      break;
  }
  
  
  
    //if button is pressed, change clickcount and set newpress to false
  if (buttonStateA == HIGH and newPressA == 1)
  {
    clickCountA++;
    newPressA = 0;  
  }
  
  //if button is let go, set newPress to 1
  if (buttonStateA == LOW) newPressA = 1;
  
  switch (clickCountA)
  {
    case 1:
      strip.setPixelColor(1, 0, 255, 0);
      strip.show();
      break;
    case 2:
      strip.setPixelColor(1, 255, 255, 0);
      strip.show();
      break;
    case 3:
      strip.setPixelColor(1, 255, 0, 0);
      strip.show();
      break;
    case 4:
      strip.setPixelColor(1, 0, 0, 0);
      strip.show();
      clickCountA = 0;
      break;
  }
  
  
  //if button is pressed, change clickcount and set newpress to false
  if (buttonStateN == HIGH and newPressN == 1)
  {
    clickCountN++;
    newPressN = 0;  
  }
  
  //if button is let go, set newPress to 1
  if (buttonStateN == LOW) newPressN = 1;
  
  switch (clickCountN)
  {
    case 1:
      strip.setPixelColor(2, 51, 204, 255);
      strip.show();
      break;
    case 2:
      strip.setPixelColor(2, 255, 74, 0);
      strip.show();
      break;
    case 3:
      strip.setPixelColor(2, 204, 51, 255);
      strip.show();
      break;
    case 4:
      strip.setPixelColor(2, 0, 0, 0);
      strip.show();
      clickCountN = 0;
      break;
  }  
  
  //if a and n buttons are pressed simultaneously, enter or exit findme mode
  if (buttonStateN == HIGH and buttonStateA == HIGH and findMe == 0)
  {
    folsom();
    delay(200);
    findMe = 1; 
  }
  
  if (buttonStateN == HIGH and buttonStateA == HIGH and findMe == 1)
  {
    off();  
    delay(200);
     findMe = 0; 
  }
  
  
  
  
  delay(100);
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



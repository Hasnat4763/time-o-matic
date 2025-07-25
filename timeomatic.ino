#include <Adafruit_SSD1306.h>
#include <splash.h>

#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <Wire.h>

Adafruit_SSD1306 smoldisplay(128, 64, &Wire, -1);
String inputString="";


void setup() {
  Serial.begin(115200);

  if (!smoldisplay.begin(SSD1306_SWITCHCAPVCC, 0x3c)){
    Serial.println("ssd1306 allocation failed");
    for(;;);
    }
  smoldisplay.clearDisplay();
  smoldisplay.setTextSize(1);
  smoldisplay.setCursor(0,0);
  smoldisplay.print("Waiting for data");
  smoldisplay.display();

}

void loop() {
  while (Serial.available()){
    char info = Serial.read();
    if (info =='\n'){
      smoldisplay.clearDisplay();
      smoldisplay.setCursor(0,0);
      smoldisplay.println("");
      smoldisplay.display();
    }
    else {
      inputString += info;
    }
  }
}

/* 
ECE411 Team 8 - Voltage Vanguard

Testing OLED display writing text to screen.
 */


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


void setup() 
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("The Voltage Vanguard");

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,17);
  display.println("SynthBuddy");
  display.display();


}

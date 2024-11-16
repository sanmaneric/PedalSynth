#include <driver/ledc.h>  // Library to control LEDC, used for PWM
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Configure Display
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
// Define clock output pin
const int clockPin = 26;   // Change this to any suitable GPIO pin

// Define button pins
const int buttonUpPin = 0;   // Pin for the "increase frequency" button
const int buttonDownPin = 4; // Pin for the "decrease frequency" button

// Define initial clock frequency in Hz
int clockFrequency = 10;  // Starting frequency (e.g., 48kHz)
const int stepSize = 1;     // Frequency step size (in Hz)
const int minFrequency = 5; // Minimum frequency (in Hz)
const int maxFrequency = 10000; // Maximum frequency (in Hz)

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("Generating clock signal with adjustable frequency...");

  // Configure the LEDC timer (using 8-bit resolution for PWM)
  ledcSetup(0, clockFrequency, 8);  // Timer 0, initial frequency, 8-bit resolution

  // Attach the clock signal to the specified GPIO pin
  ledcAttachPin(clockPin, 0);

  // Set button pins as inputs
  pinMode(buttonUpPin, INPUT_PULLUP);   // Use internal pull-up resistor
  pinMode(buttonDownPin, INPUT_PULLUP); // Use internal pull-up resistor

  // Set initial duty cycle
  ledcWrite(0, 128);  // Set duty cycle to 50% (128 out of 255)
}

void loop() {
  // Read button states
  int buttonUpState = digitalRead(buttonUpPin);
  int buttonDownState = digitalRead(buttonDownPin);

  // Increase frequency if the "up" button is pressed
  if (buttonUpState == LOW) {  // Button pressed (LOW for active state)
    if (clockFrequency + stepSize <= maxFrequency) {
      clockFrequency += stepSize;
      Serial.print("Frequency increased to: ");
      Serial.println(clockFrequency);
      updateClockFrequency();
      delay(50);  // Debounce delay
    }
  }

  // Decrease frequency if the "down" button is pressed
  if (buttonDownState == LOW) {  // Button pressed (LOW for active state)
    if (clockFrequency - stepSize >= minFrequency) {
      clockFrequency -= stepSize;
      Serial.print("Frequency decreased to: ");
      Serial.println(clockFrequency);
      updateClockFrequency();
      delay(50);  // Debounce delay
    }
  }
}

// Function to update clock frequency
void updateClockFrequency() {
  // Reconfigure the timer with the new frequency
  ledcSetup(0, clockFrequency, 8);  // Timer 0, updated frequency, 8-bit resolution
    display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("FUNCTION GENERATOR");

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,17);
  display.print("Freq: ");
  display.print(clockFrequency);
  display.println(" Hz");
  display.display();
}
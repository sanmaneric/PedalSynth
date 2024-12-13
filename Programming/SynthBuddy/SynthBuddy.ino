#include <driver/ledc.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define PWM properties
#define PWM_RESOLUTION 8     // Resolution in bits (0-255)
#define PWM_CHANNEL 0        // PWM channel number
#define PWM_PIN 35           // Pin for PWM output
#define OLED_RESET -1        // Reset pin for OLED (not used)
#define SCREEN_ADDRESS 0x3C  // I2C address of the OLED

// Button pins for frequency selection
const int buttonPins[] = {12, 14, 25, 26, 27, 32, 33};
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);

// Frequency options in Hz
const int frequencies[] = {130.81, 146.83, 164.81,  174.61, 196.00, 220.00, 246.94};
int currentFrequencyIndex = 0; // Current frequency index

// OLED display object
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.display();

  // Setup PWM on the specified pin
  ledcSetup(PWM_CHANNEL, frequencies[currentFrequencyIndex], PWM_RESOLUTION);
  ledcAttachPin(PWM_PIN, PWM_CHANNEL);

  // Setup button pins as input with internal pull-up resistors
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Initial display update
  updateDisplay();
}

void loop() {
  // Check each button
  for (int i = 0; i < numButtons; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      // Change frequency based on the button pressed
      currentFrequencyIndex = i;
      ledcSetup(PWM_CHANNEL, frequencies[currentFrequencyIndex], PWM_RESOLUTION);
      ledcAttachPin(PWM_PIN, PWM_CHANNEL);

      // Update OLED display
      updateDisplay();

      // Debounce delay
      delay(200);
    }
  }
}

void updateDisplay() {
  // Clear the display
  display.clearDisplay();

  // Display the current frequency
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Frequency Control"));
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(frequencies[currentFrequencyIndex]);
  display.println(F(" Hz"));

  // Update the display
  display.display();
}
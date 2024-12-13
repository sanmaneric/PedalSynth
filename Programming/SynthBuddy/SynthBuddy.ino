#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define PWM_PIN 23
#define PWM_RESOLUTION 8
#define PWM_FREQ 50000

const int buttonPins[] = {12, 14, 27, 26, 25, 33, 32};
const float frequencies[] = {130.8, 146.8, 164.8, 174.2, 196.0, 220.0, 246.94};
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);

hw_timer_t *timer = NULL;
volatile bool waveActive = false;
volatile uint8_t sineIndex = 0;
volatile float currentFrequency = 0;
const int sineTableSize = 256;
uint8_t sineTable[sineTableSize];

void IRAM_ATTR onTimer() {
  if (waveActive) {
    uint8_t pwmValue = sineTable[sineIndex];
    ledcWrite(0, pwmValue);
    sineIndex = (sineIndex + 1) % sineTableSize;
  } else {
    ledcWrite(0, 0); // Turn off PWM when no button is pressed
  }
}

void setup() {
  // Initialize OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // Initialize sine wave lookup table
  for (int i = 0; i < sineTableSize; i++) {
    sineTable[i] = (sin(2 * PI * i / sineTableSize) + 1.0) * 127.5;
  }

  // Configure buttons as inputs with pull-up resistors
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Configure PWM on the output pin
  ledcSetup(0, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(PWM_PIN, 0);

  // Initialize timer
  timer = timerBegin(0, 80, true); // 80 prescaler for 1 µs ticks
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 100, true); // 100 µs (10 kHz timer frequency)
  timerAlarmEnable(timer);
}

void loop() {
  waveActive = false;
  for (int i = 0; i < numButtons; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      waveActive = true;
      currentFrequency = frequencies[i];
      sineIndex = 0;

      // Adjust timer frequency for current sine wave
      timerAlarmWrite(timer, (1000000 / currentFrequency) / sineTableSize, true);

      // Update OLED display with current frequency
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);
      display.println("SynthBuddy");

      display.setCursor(0, 16);
      display.setTextSize(1);
      display.println("Frequency:");
      display.print(currentFrequency);
      display.println(" Hz");

      display.display();
      break;
    }
  }
}
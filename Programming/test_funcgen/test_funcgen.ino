#include <driver/ledc.h>

// Define PWM properties
#define PWM_RESOLUTION 8     // Resolution in bits (0-255)
#define PWM_CHANNEL 0        // PWM channel number
#define PWM_PIN 25           // Pin for PWM output

// Button pins
#define SINE_BUTTON_PIN 2
#define SQUARE_BUTTON_PIN 4
#define TRIANGLE_BUTTON_PIN 16
#define FREQ_BUTTON_PINS {17, 18, 19, 21, 22} // Array of pins for frequency selection

// Variables for waveform generation
const int sineTableSize = 256;
uint8_t sineTable[sineTableSize];
uint8_t triangleTable[sineTableSize];
uint8_t squareTable[sineTableSize];

int currentFrequency = 0; // Index to store current frequency
int currentWaveform = 0;  // 0 = sine, 1 = square, 2 = triangle

// Frequency options in Hz
const int frequencies[] = {1000, 2000, 3000, 4000, 5000};

// Function to generate sine wave lookup table
void generateSineTable() {
  for (int i = 0; i < sineTableSize; i++) {
    sineTable[i] = (sin(2 * PI * i / sineTableSize) * 127) + 128; // Scaled to 0-255
  }
}

// Function to generate triangle wave lookup table
void generateTriangleTable() {
  for (int i = 0; i < sineTableSize; i++) {
    if (i < sineTableSize / 2) {
      triangleTable[i] = (i * 255) / (sineTableSize / 2);
    } else {
      triangleTable[i] = 255 - ((i - sineTableSize / 2) * 255) / (sineTableSize / 2);
    }
  }
}

// Function to generate square wave lookup table
void generateSquareTable() {
  for (int i = 0; i < sineTableSize; i++) {
    squareTable[i] = (i < sineTableSize / 2) ? 0 : 255;
  }
}

// Setup PWM and input buttons
void setup() {
  Serial.begin(115200);

  // Setup PWM on the specified pin
  ledcSetup(PWM_CHANNEL, frequencies[currentFrequency], PWM_RESOLUTION);
  ledcAttachPin(PWM_PIN, PWM_CHANNEL);

  // Generate wave tables
  generateSineTable();
  generateTriangleTable();
  generateSquareTable();

  // Setup button pins as input with internal pull-up resistors
  pinMode(SINE_BUTTON_PIN, INPUT_PULLUP);
  pinMode(SQUARE_BUTTON_PIN, INPUT_PULLUP);
  pinMode(TRIANGLE_BUTTON_PIN, INPUT_PULLUP);

  int freqButtons[] = FREQ_BUTTON_PINS;
  for (int i = 0; i < 5; i++) {
    pinMode(freqButtons[i], INPUT_PULLUP);
  }
}

void loop() {
  // Check waveform selection buttons
  if (digitalRead(SINE_BUTTON_PIN) == LOW) {
    currentWaveform = 0;
    Serial.println("Sine Wave Selected");
    delay(200); // Debounce delay
  } else if (digitalRead(SQUARE_BUTTON_PIN) == LOW) {
    currentWaveform = 1;
    Serial.println("Square Wave Selected");
    delay(200);
  } else if (digitalRead(TRIANGLE_BUTTON_PIN) == LOW) {
    currentWaveform = 2;
    Serial.println("Triangle Wave Selected");
    delay(200);
  }

  // Check frequency selection buttons
  int freqButtons[] = FREQ_BUTTON_PINS;
  for (int i = 0; i < 5; i++) {
    if (digitalRead(freqButtons[i]) == LOW) {
      currentFrequency = i;
      ledcSetup(PWM_CHANNEL, frequencies[currentFrequency], PWM_RESOLUTION);
      ledcAttachPin(PWM_PIN, PWM_CHANNEL);
      Serial.print("Frequency set to: ");
      Serial.println(frequencies[currentFrequency]);
      delay(200); // Debounce delay
    }
  }

  // Generate the selected waveform at the selected frequency
  for (int i = 0; i < sineTableSize; i++) {
    switch (currentWaveform) {
      case 0:
        ledcWrite(PWM_CHANNEL, sineTable[i]);
        break;
      case 1:
        ledcWrite(PWM_CHANNEL, squareTable[i]);
        break;
      case 2:
        ledcWrite(PWM_CHANNEL, triangleTable[i]);
        break;
    }
    delayMicroseconds(1000000 / (frequencies[currentFrequency] * sineTableSize)); // Adjust for waveform timing
  }
}
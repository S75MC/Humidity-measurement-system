
// Include required libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>

// Define OLED display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Initialize OLED display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Define pins for sensors and Bluetooth
#define MOISTURE_SENSOR_PIN A0
#define MIN_HUMIDITY 30
#define MAX_HUMIDITY 70

SoftwareSerial bluetooth(10, 11); // RX, TX for Bluetooth

// Variables to store sensor data
int soilMoistureValue = 0;
String soilCondition = "Normal";

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);
  bluetooth.begin(9600);

  // Initialize OLED display
  if (!display.begin(SSD1306_I2C_ADDRESS, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Initial screen
  display.setCursor(0, 10);
  display.println("Humidity measurement system");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  // Read soil moisture value
  soilMoistureValue = analogRead(MOISTURE_SENSOR_PIN);

  // Convert to percentage
  int moisturePercentage = map(soilMoistureValue, 0, 1023, 0, 100);

  // Determine soil condition
  if (moisturePercentage < MIN_HUMIDITY) {
    soilCondition = "Dry";
  } else if (moisturePercentage > MAX_HUMIDITY) {
    soilCondition = "Saturated";
  } else {
    soilCondition = "Normal";
  }

  // Display data on OLED
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Humidity percentage:");
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(moisturePercentage);
  display.println("%");

  display.setTextSize(1);
  display.setCursor(0, 40);
  display.print("Soil Condition: ");
  display.println(soilCondition);

  display.display();

  // Send data via Bluetooth
  bluetooth.print("Moisture: ");
  bluetooth.print(moisturePercentage);
  bluetooth.println("%");
  bluetooth.print("Condition: ");
  bluetooth.println(soilCondition);

  delay(2000); // Delay for 2 seconds
}

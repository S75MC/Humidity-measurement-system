
/*
  Voltaat learn (https://www.voltaat.com)
  Link for full tutorial:
  
  LiquidCrystal I2C Library: https://learn.voltaat.com/wp-content/uploads/2023/05/LCD_library.zip

  Tutorial: Build an auto watering system for plants using Arduino
  
  The function of this code is to pump water to the plant when the plants need water and stop the pump
  if the soil of the plants is sufficiently saturated with water, and printing the status of whether the plants
  need water or not on a crystal screen.

  Connections from the Arduino to the breadboard:
  
  • Arduino 5v pin → breadboard 5v line
  • Arduino GND pin → breadboard GND line


  Connections from the Soil Moisture Sensor:

  • VCC pin → breadboard 5v line
  • GND pin → breadboard GND line
  • A0 pin → Arduino pin A0

  Connections from the npn transistor:

  • the emitter → breadboard GND line 
  • the base → resistor → Arduino pin 3

  Connections from the pump :

  • the first wire → the collector 
  • The second wire → breadboard 5v line 

  Connection from the LCD:

  • VCC pin → breadboard 5v line
  • GND pin→ breadboard GND line
  • SDA pin→ Arduino analog pin A4
  • SCL pin → Arduino analog pin A5

*/

#include <LiquidCrystal_I2C.h>  // Include the LiquidCrystal_I2C library

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Create an instance of the LiquidCrystal_I2C class with the specified address and dimensions

int soilMoistureValue = 0;  // Variable to store the analog reading of soil moisture
int percentage = 0;  // Variable to store the calculated percentage of soil moisture

void setup() {
  pinMode(3, OUTPUT);  // Set pin 3 as an output pin
  lcd.init();  // Initialize the LCD display
  lcd.backlight();  // Turn on the backlight of the LCD
  lcd.clear();  // Clear the LCD display
  digitalWrite(3, LOW);  // Set pin 3 to a low state (initially turn off the pump)
}

void loop() {
  soilMoistureValue = analogRead(A0);  // Read the analog value from pin A0 connected to the soil moisture sensor
  percentage = map(soilMoistureValue, 490, 1023, 100, 0);  // Map the analog value to a percentage value between 0 and 100

  if (percentage < 20) {
    digitalWrite(3, HIGH);  // Turn on the pump (set pin 3 to a high state)
    lcd.setCursor(0, 0);
    lcd.print("The Plants need "); // print on the LCD display
    lcd.setCursor(0, 1);
    lcd.print("water  ");
    lcd.setCursor(8, 1);
    lcd.print(" PUMP ON");
  }

  if (percentage > 80) {
    digitalWrite(3, LOW);  // Turn off the pump (set pin 3 to a low state)
    lcd.setCursor(0, 0);
    lcd.print("Plants have been");
    lcd.setCursor(0, 1);
    lcd.print("watered");
    lcd.setCursor(8, 1);
    lcd.print("PUMP OFF");
  }
}
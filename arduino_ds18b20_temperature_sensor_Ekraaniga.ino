// This Arduino sketch reads DS18B20 "1-Wire" digital
// temperature sensors.
// Tutorial:
// http://www.hacktronics.com/Tutorials/arduino-1-wire-tutorial.html

#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

int reading = 0;
int sensorPin = A0;
int relay =7;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);


// Data wire is plugged into pin 3 on the Arduino
#define ONE_WIRE_BUS 11

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// Assign the addresses of your 1-Wire temp sensors.
// See the tutorial on how to obtain these addresses:
// http://www.hacktronics.com/Tutorials/arduino-1-wire-address-finder.html

DeviceAddress insideThermometer = { 0x28, 0x71, 0x70, 0xCE, 0x04, 0x00, 0x00, 0x6E }; // andur 1
DeviceAddress outsideThermometer = { 0x28, 0x0A, 0x7B, 0xCD, 0x04, 0x00, 0x00, 0xF6 }; // andur 5
//DeviceAddress andurKaksThermometer = { 0x28, 0xE5, 0x47, 0xC0, 0x04, 0x00, 0x00, 0xC3 }; // andur 2
//DeviceAddress andurKolmThermimeter = { 0x28, 0x15, 0x0C, 0xCE, 0x04, 0x00, 0x00, 0x3D }; // andur 3
//DeviceAddress andurNeliThermometer = { 0x28, 0x86, 0x9F, 0xCE, 0x04, 0x00, 0x00, 0x2C }; // andur 4


void setup(void)
{
  // start serial port
  Serial.begin(9600);
  // Start up the library
  sensors.begin();
  // set the resolution to 10 bit (good enough?)
  sensors.setResolution(insideThermometer, 10);
  sensors.setResolution(outsideThermometer, 10);
  //sensors.setResolution(andurKaksThermometer, 10);
  //sensors.setResolution(andurKolmThermometer, 10);
  //sensors.setResolution(andurNeliThermometer, 10);
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
 pinMode(relay,OUTPUT);
}

void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
  if (tempC == -127.00) {
    Serial.print("Mingi jama ....");
  } else {
    Serial.print("C: ");
    Serial.print(tempC);
    //Serial.print(" F: ");
    //Serial.print(DallasTemperature::toFahrenheit(tempC));
  }
}

void loop(void)
{ 
  delay(2000);
  Serial.print("Kohe-kohe...\n\r");
  sensors.requestTemperatures();
  lcd.print("Arduino"); // Prints "Arduino" on the LCD 
  
  Serial.print("Andur nr. 1 on: ");
  printTemperature(insideThermometer);
  Serial.print("\n\r\n\r");
  Serial.print("Andur nr. 5 on: ");
  printTemperature(outsideThermometer);
  Serial.print("\n\r\n\r");
  //Serial.print("Anduri nr. 1 näit on: ");
  //printTemperature(andurKaksThermometer);
  //Serial.print("\n\r\n\r");
  //Serial.print("Anduri nr. 1 näit on: ");
  //printTemperature(andurKolmThermometer);
  //Serial.print("\n\r\n\r");
  //Serial.print("Anduri nr. 1 näit on: ");
  //printTemperature(andurNeliThermometer);
  //Serial.print("\n\r\n\r");
  //Serial.print("Dog House temperature is: ");
  //printTemperature(dogHouseThermometer);
  //Serial.print("\n\r\n\r");
}



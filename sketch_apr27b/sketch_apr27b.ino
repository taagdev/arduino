    #include <LiquidCrystal.h>
    byte slash[8]= { // Array of bytes
      B00001,  // B stands for binary formatter and the 5 numbers are the pixels
      B00010,
      B00100,
      B01000,
      B10000,
      B00000,
      B00000,
      B00000,
    };
    LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)
    void setup() { 
      lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
      lcd.createChar(7, slash); // Create a custom character for use on the LCD. Up to eight characters of 5x8 pixels are supported
    }
    void loop() { 
      for(int i=0;i<=15;i++) {
        lcd.setCursor(i,0); // Sets the location at which subsequent text written to the LCD will be displayed
        lcd.write(7); // Writes a character to the LCD
        delay(1000); // 1 second delay
        lcd.clear(); // Write a character to the LCD
      }
    }

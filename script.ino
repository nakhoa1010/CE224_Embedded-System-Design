#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define PIN_IN  2
#define PIN_OUT 3

LiquidCrystal_I2C lcd(0X27, 16, 2); //SCL A5 SDA A4

int count = 0;

void setup() {
    // put your setup code here, to run once:
    // init lcd i2c
    lcd.init();
    lcd.backlight();
    // init pin mode
    pinMode(PIN_IN , INPUT);
    pinMode(PIN_OUT, INPUT);
}

void counting(bool mode) {
    if ( mode && (count < 10)) count++;
    if (!mode && (count >   0)) count--;
}

void lcd_print() {
    if (count == 10) {
        lcd.setCursor(4, 0);
        lcd.print("$ FULL $");
    }
    else {
        lcd.setCursor(3, 0);
        lcd.print("$ WELCOME $");
    }
    lcd.setCursor(0, 1);
    lcd.print("QTY: ");
    lcd.print(count);
    lcd.print(" PEOPLE");
    delay(320);
    lcd.clear();
}

void loop() {
    // put your main code here, to run repeatedly:
    if (!digitalRead(PIN_IN )) {
        while(!digitalRead(PIN_IN ));
        counting(1);
        
    }
    if (!digitalRead(PIN_OUT)) {
        while(!digitalRead(PIN_OUT));
        counting(0);
    }
    lcd_print();
}

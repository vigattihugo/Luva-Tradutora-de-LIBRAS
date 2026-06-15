
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 

LiquidCrystal_I2C lcd(0x27, 16, 2); 
 

int FLEX_PIN1 = A0;
int FLEX_PIN2 = A1;
int FLEX_PIN3 = A2;
int FLEX_PIN4 = A3;
 

int flexADC1 = 0;
int flexADC2 = 0;
int flexADC3 = 0;
int flexADC4 = 0;
 
void setup() {
    
    lcd.init();
    lcd.backlight();
 
    
    lcd.setCursor(0, 0);
    lcd.print("Iniciando...");
    delay(2000);
    lcd.clear();
}
 
void loop() {
    
    flexADC1 = analogRead(FLEX_PIN1);
    flexADC2 = analogRead(FLEX_PIN2);
    flexADC3 = analogRead(FLEX_PIN3);
    flexADC4 = analogRead(FLEX_PIN4);
 
    
    flexADC1 = map(flexADC1, 6, 33, 100, 0);
    flexADC2 = map(flexADC2, 6, 33, 100, 0);
    flexADC3 = map(flexADC3, 6, 33, 100, 0);
    flexADC4 = map(flexADC4, 6, 33, 100, 0);
 
    
    lcd.clear();
 
   
    if (((flexADC1 >= 0) && (flexADC1 <= 70)) &&
        ((flexADC2 >= 0) && (flexADC2 <= 70)) &&
        ((flexADC3 >= 0) && (flexADC3 <= 70)) &&
        ((flexADC4 >= 60) && (flexADC4 <= 100))) {
        lcd.print("Gostei");
    }
    if (((flexADC1 >= 0) && (flexADC1 <= 70)) &&
        ((flexADC2 >= 60) && (flexADC2 <= 100)) &&
        ((flexADC3 >= 0) && (flexADC3 <= 70)) &&
        ((flexADC4 >= 0) && (flexADC4 <= 70))) {
        lcd.print("Nao gostei");
    }
    if (((flexADC1 >= 0) && (flexADC1 <= 70)) &&
        ((flexADC2 >= 0) && (flexADC2 <= 70)) &&
        ((flexADC3 >= 60) && (flexADC3 <= 100)) &&
        ((flexADC4 >= 0) && (flexADC4 <= 70))) {
        lcd.print("Beber agua");
    }
    if (((flexADC1 >= 0) && (flexADC1 <= 70)) &&
        ((flexADC2 >= 60) && (flexADC2 <= 100)) &&
        ((flexADC3 >= 60) && (flexADC3 <= 100)) &&
        ((flexADC4 >= 0) && (flexADC4 <= 70))) {
        lcd.print("Ir ao banheiro");
    }
    if (((flexADC1 >= 60) && (flexADC1 <= 100)) &&
        ((flexADC2 >= 0) && (flexADC2 <= 70)) &&
        ((flexADC3 >= 0) && (flexADC3 <= 70)) &&
        ((flexADC4 >= 0) && (flexADC4 <= 70))) {
        lcd.print("Ajuda");
    }
    if (((flexADC1 >= 60) && (flexADC1 <= 100)) &&
        ((flexADC2 >= 0) && (flexADC2 <= 70)) &&
        ((flexADC3 >= 0) && (flexADC3 <= 70)) &&
        ((flexADC4 >= 60) && (flexADC4 <= 100))) {
        lcd.print("Obrigado");
    }
 
    delay(2000); 
}

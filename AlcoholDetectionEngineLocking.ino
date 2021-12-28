#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
const int ledPin=13;
const int m1=8;
const int m2=9; 
const int button_input=10;
const int button_output=11;
const int threshold=600;
int buttonstate;
int LED1 = 13;


void setup() {
  lcd.begin(16,2); 
  lcd.init();
  lcd.backlight();   
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(A0,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(button_input,INPUT);
  pinMode(button_output,OUTPUT);
  digitalWrite (button_output,HIGH);
}

void loop() {
    lcd.clear();  
    int a=analogRead(A0);
    Serial.println(a);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ANGRY NERDS");
    lcd.setCursor(0,1);
    delay(500);
    buttonstate=digitalRead(button_input);
    if(a>threshold) 
    {
      if (buttonstate==1)
      {
        digitalWrite(ledPin,1);
        digitalWrite(m1,0);
        digitalWrite(m2,0);
        tone(12,1600);
        digitalWrite(LED1, HIGH);    
        delay(200);                  
        digitalWrite(LED1, LOW);     
        delay(100);             
        lcd.print("DRIVER DRUNK");
        delay(1000);
      } 
      else if (buttonstate==0)
      {
        digitalWrite (m1,0);
        digitalWrite (m2,0);
        lcd.print("ENGINE STOPPED");
        delay (1000);
      }
    }
    else if (a<threshold)
        {
          if (buttonstate==1)
          {
            digitalWrite(ledPin,0);
            digitalWrite(m1,1);
            digitalWrite(m2,0);
            lcd.print("NORMAL LEVEL....");
            noTone(12);
            delay(1000);
          }
          else if (buttonstate==0)
          {
            digitalWrite (m1,0);
            digitalWrite (m2,0);
            lcd.print("START ENGINE");
            delay(1000);
          }
          
        }
}

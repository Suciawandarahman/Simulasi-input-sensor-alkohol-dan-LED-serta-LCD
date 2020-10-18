#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int GAS_SENSOR=3;
int YELLOW_LED=5;
int RED_LED=4;
void setup() {
  // put your setup code here, to run once:
pinMode (GAS_SENSOR, INPUT_PULLUP);
pinMode (YELLOW_LED, OUTPUT);
pinMode (RED_LED, OUTPUT);
lcd.begin (20, 4);
lcd.setCursor (0, 0);
lcd.print ("SISTEM PENDETEKSI");
lcd.setCursor (0,1);
lcd.print ("ALKOHOL");
lcd.setCursor (0, 2);
lcd.print ("TELEKOMUNIKASI PNJ");
delay(1000);
}

void loop (){
  int GAS_SENSOR_READ = digitalRead(GAS_SENSOR);
  if (GAS_SENSOR_READ == LOW)
  {
    lcd.clear();
    lcd.setCursor(0, 3);
    lcd.print("ALKOHOL DETECTED");
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    delay(20);
  }
  else //oterwise
  {
    lcd.clear();
    lcd.setCursor(0, 3);
    lcd.print("ALKOHOL NOT DETECTED");
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    delay(20);
  }
}

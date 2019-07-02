#include <LiquidCrystal.h>
int temp;
LiquidCrystal lcd(16,17,23,25,27,29);
void setup() {
  // put your setup code here, to run once:
lcd.begin(20,4);

}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);
temp = analogRead(13);
lcd.print("siema");
lcd.print(temp);

}
#define TEMP_0_PIN         13   // Analog Input
#define TEMP_1_PIN         15   // Analog Input
#define TEMP_BED_PIN       14   // Analog Input
#define a -5.30377404285076e-07
#define b 0.000913895174164941
#define c -0.619287460375456
#define d 250.544163050966




#ifndef MOSFET_D_PIN
  #define MOSFET_D_PIN     -1
#endif
#ifndef RAMPS_D8_PIN
  #define RAMPS_D8_PIN      8
#endif
#ifndef RAMPS_D9_PIN
  #define RAMPS_D9_PIN      9
#endif
#ifndef RAMPS_D10_PIN
  #define RAMPS_D10_PIN    10
#endif

#define HEATER_0_PIN       RAMPS_D10_PIN




#include <LiquidCrystal.h>
LiquidCrystal lcd(16, 17, 23, 25, 27, 29);
int temp;
double pomiar;
double x;
int czas=0;
void setup() 
{
  lcd.begin(20, 4);
  pinMode(HEATER_0_PIN, OUTPUT);
}

void loop() 
{
  temp = analogRead(13);
  x = (double) temp;
  pomiar = a*x*x*x+b*x*x+c*x+d;
  lcd.setCursor(0, 0);
  lcd.print(pomiar);
  if(czas <= 50)
  {
    digitalWrite(HEATER_0_PIN, HIGH);
    czas++;
  }
  else
  {
    digitalWrite(HEATER_0_PIN, LOW);
  }
  delay(100);
  
  
}
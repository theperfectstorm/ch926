// ABHISHEK SINGH on github @ theperfectstorm

/*The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 6
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 4
 * LCD D7 pin to digital pin 3
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/



///////////////////////////////////////////////////////////
//print total value and turn on digital output when     //
// value reaches 30,then reset last values             //
////////////////////////////////////////////////////////
#include <LiquidCrystal.h>

#define int_pin 2
const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//connect output of ch926 to pin 2 on arduino
int val=0;// total value of coins inserted till now
int denom=0; //coin value
int count=0;
void setup() {
attachInterrupt(digitalPinToInterrupt(int_pin),countISR,CHANGE);
Serial.begin(9600);
lcd.begin(16, 2); //16 characters* 2 columns
pinMode(13,OUTPUT);
digitalWrite(13,LOW);//turn of led 13 in the beginning
}
void act()
{
  lcd.clear();
  lcd.print("You inserted a total of Rs 30");
  delay(1000);
  lcd.clear();
  lcd.print("Turning on heater!"); //check for pin13
  {
    digitalWrite(13,HIGH);
  }
  
  val=0;
  count=0;
  denom=0;
}
void loop() {
if(val==30) //30 rs for 1 corn
{
  act();
}


}
void calc()
{
  if(count==4||count==5) //pulses for 5 rs
  {
    denom=5;
    count=0; //reset count value for taking new reading
    lcd.clear();
    lcd.print("5 rs coin inserted,total val:");
    lcd.print(denom);
  }
  else if(count==10)//assuming 10 pulses for rs 10 coin
  {
    denom=10;
    count=0;
    denom=5;
    count=0; //reset count value for taking new reading
    lcd.clear();
    lcd.print("5 rs coin inserted,total val:");
    lcd.print(denom);
  }
  else{denom=0;} //invalid coin detection
val+=denom;
  
}
void countISR()
{
  count++;
  calc();
}


// ABHISHEK SINGH on github @ theperfectstorm


#define int_pin 2
//connect output of ch926 to pin 2 on arduino

int count=0;
void setup() {
attachInterrupt(digitalPinToInterrupt(int_pin),countISR,RISING);
Serial.begin(9600);
}

void loop() {
Serial.print("Pulse Counts: ");
Serial.println(count);
}

void countISR()
{
  count++;
}


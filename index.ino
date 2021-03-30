#include <string.h>

String squares[4] = {"A1", "A2", "B1", "B2"};

#define C1 2
#define C2 3
#define C3 4
#define C4 5

void setup()
{
  Serial.begin(115200);
  pinMode(C1, INPUT);
  pinMode(C2, INPUT);
  pinMode(C3, INPUT);
  pinMode(C4, INPUT);
}

void loop()
{
  Serial.println("CASA 1: " + String(digitalRead(C1)));
  Serial.println("CASA 2: " + String(digitalRead(C2)));
  Serial.println("CASA 3: " + String(digitalRead(C3)));
  Serial.println("CASA 4: " + String(digitalRead(C4)));
  Serial.println("----------------------------------");
  delay(1000);
}
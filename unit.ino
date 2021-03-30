#include <string.h>

String squares[4] = {"A1", "A2", "B1", "B2"};

#define C1 2
#define C2 3
#define C3 4
#define C4 5
#define C5 6
#define C6 7

int xPos = 0;
int yPos = 0;

void getCooridanates(){
    int x[3] = {digitalRead(C1), digitalRead(C2), digitalRead(C3)};
    int y[3] = {digitalRead(C4), digitalRead(C5), digitalRead(C6)};
    for (auto &&i : x)
    {
        if (i = 1)
        {
            for (auto &&i : y){
                if(i = 1){
                    yPos = i;
                }
            }
            xPos = i;   
        }
    }
    Serial.printf(String(xPos) + ";" + String(yPos));
}

void setup()
{
  Serial.begin(115200);
  pinMode(C1, INPUT);
  pinMode(C2, INPUT);
  pinMode(C3, INPUT);
  pinMode(C4, INPUT);
  pinMode(C5, INPUT);
  pinMode(C6, INPUT);
}

void loop()
{
//   Serial.println("X1 - (1): " + String(digitalRead(C1)));
//   Serial.println("X2 - (2): " + String(digitalRead(C2)));
//   Serial.println("X3 - (3): " + String(digitalRead(C3)));
//   Serial.println("Y1 - (4): " + String(digitalRead(C4)));
//   Serial.println("Y2 - (5): " + String(digitalRead(C5)));
//   Serial.println("Y3 - (6): " + String(digitalRead(C6)));
//   Serial.println("----------------------------------");
  getCooridanates();
  delay(1000);
}
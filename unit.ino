#include <string.h>

#define C1 2
#define C2 3
#define C3 4
#define C4 5
#define C5 6
#define C6 7

int xPos = 0;
int yPos = 0;

void getCooridanates(){
    for (int i = 0; i < 3; i++)
    { 
        int i_verification = digitalRead(i);
        if (i_verification = 1)
        {
            for (int j = 0; j < 3; j++)
            {
                int j_verification = digitalRead(j);
                if (j_verification = 1)
                {
                    yPos = j;
                }
                
            }
            xPos = i;
        }
    }
    Serial.println(String(xPos) + ";" + String(yPos));
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
  getCooridanates();
  delay(1000);
}

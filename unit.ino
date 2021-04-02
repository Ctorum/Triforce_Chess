#include <string.h>

#define C1 2
#define C2 3
#define C3 4
#define C4 5
#define C5 6
#define C6 7
#define C7 8
#define C8 9

int xPos = 0;
int yPos = 0;

int xPosAux = 0;
int yPosAux = 0;

String coordinates[8] = {"1", "2", "3", "4", "A", "B", "C", "D"};

void getCoordinates()
{
    for (int i = 0; i < 64; i++)
    {
        for (int i = 2; i < 6; i++)
        {
            int i_verification = digitalRead(i);
            //Comment here to house analysis
            if (i_verification == 1)
            {
                for (int j = 6; j < 10; j++)
                {
                    int j_verification = digitalRead(j);
                    if (j_verification == 1)
                    {
                        xPos = j;
                        xPosAux = xPos;
                    }
                }
                yPos = i;
                yPosAux = yPos;
            }
            //Finish coment here
            //Serial.println(i + ": " + i_verification)
        }



        if (xPos != yPosAux || yPos != yPosAux) {
            Serial.println(String(coordinates[xPos - 2]) + String(coordinates[yPos - 2]));
        }
    }

    Serial.println("--------------------------------");
    
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
    pinMode(C7, INPUT);
    pinMode(C8, INPUT);
}

void loop()
{
    getCoordinates();
    delay(1000);
}

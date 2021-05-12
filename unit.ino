#include "create_board.h"
#define boardWidth 4

int powerPins[4] = {50,51,52,53};

String positions[boardWidth * boardWidth];

String letterPositions[8] = {"A","B","C","D","E","F","G","H"};
String numberPositions[8] = {"1","2","3","4","5","6","7","8"};

void setup() {
  Serial.begin(115200);
  for (int x : powerPins) {
    pinMode(x, OUTPUT);
    digitalWrite(x, LOW);
  }

  for (int i = 30; i < 38; i++) {
    pinMode(i, INPUT);
  }
}

void readHouses() {
  for (int i = 0; i < sizeof(positions)/sizeof(positions[0]); i++)
  {
    positions[i] = "";
  }
  
  int horizontalInitializer = 34;
  int verticalInitializer = 30;
  
  for (int x : powerPins) {
    digitalWrite(x, HIGH);

    for(int y = 0; y < boardWidth; y++) {
      if (digitalRead(verticalInitializer + y) == HIGH) {
        int horizontalState[boardWidth];
        
        for(int j = 0; j < boardWidth; j++) {
          int state = digitalRead(horizontalInitializer + j);
          if (state == HIGH) {
            horizontalState[j] = 1;
          } else {
            horizontalState[j] = 0;
          }
        }

        for (int e = 0; e < boardWidth; e++) {
          if (horizontalState[e] == 1) {
            for (int p = 0; p < sizeof(positions)/sizeof(positions[0]); p++) {
              if (positions[p] == NULL) {
                positions[p] = String(letterPositions[y] + numberPositions[y]);
                break;
              }
            }
          }
        }
      }
    }
    
    digitalWrite(x, LOW);
  }

  for(String pos : positions) {
    if (pos != NULL) {
      Serial.println(pos);
    }
  }

//  Serial.println(positions[0]);
}

void loop() {
  CreateBoard board("vito", "vitão");
  readHouses();
  delay(2500);
}
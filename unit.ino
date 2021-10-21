#include "board.h"
#include <ArduinoJson.h>

#define boardWidth 8

int powerPins[8] = {
  28,
  29,
  30,
  31,
  32,
  33,
  34,
  35
};

String positions[boardWidth * boardWidth];

String letterPositions[8] = {
  "A",
  "B",
  "C",
  "D",
  "E",
  "F",
  "G",
  "H"
};
String numberPositions[8] = {
  "1",
  "2",
  "3",
  "4",
  "5",
  "6",
  "7",
  "8"
};

void sendJson() {
  StaticJsonDocument<32> doc;

  for (int i = 0; i < sizeof(positions) / sizeof(positions[0]); i++) {
    if (positions[i] != NULL) {
      doc[i] = positions[i];
    }
  }

  String json;

  serializeJson(doc, json);
//  Serial.println(json);
}

void setup() {
  Serial.begin(115200);
  for (int x: powerPins) {
    pinMode(x, OUTPUT);
    digitalWrite(x, LOW);
  }

//  digitalWrite(32, HIGH);

  for (int i = 36; i < 52; i++) {
    pinMode(i, INPUT);
  }
}

void readHouses() {
  for (int i = 0; i < sizeof(positions) / sizeof(positions[0]); i++) {
    positions[i] = "";
  }

  int horizontalInitializer = 44;
  int verticalInitializer = 36;

  for (int x: powerPins) {
    digitalWrite(x, HIGH);

    for (int y = 0; y < boardWidth; y++) {
      if (digitalRead(verticalInitializer + y) == HIGH) {
        int horizontalState[boardWidth];

        for (int j = 0; j < boardWidth; j++) {
          int state = digitalRead(horizontalInitializer + j);
          if (state == HIGH) {
            horizontalState[j] = 1;
          } else {
            horizontalState[j] = 0;
          }
        }

        for (int e = 0; e < boardWidth; e++) {
          if (horizontalState[e] == 1) {
            for (int p = 0; p < sizeof(positions) / sizeof(positions[0]); p++) {
              if (positions[p] == '\0') {
                positions[p] = String(letterPositions[y] + numberPositions[e]);
                break;
              }
            }
          }
        }
      }
    }

    digitalWrite(x, LOW);
  }

  for (String pos: positions) {
    if (pos != NULL) {
      Serial.println(pos);
    }
  }

//    Serial.println(positions[0]);
}

void loop() {
  Board board(positions);
//  Serial.println(digitalRead(48));
  readHouses();
  sendJson();
  delay(1000);
}

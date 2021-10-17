#ifndef BOARD_H_
#define BOARD_H_

class Board {
  private:
    int true_check_a[8];
  int true_check_b[8];
  int true_check_g[8];
  int true_check_h[8];

  void check_a() {
    for (unsigned int i = 0; i < 8; i++) {
      if (coordinates[i] == "A%d", i) {
        true_check_a[i] = 1;
      } else {
        true_check_a[i] = 0;
      }
    }
  }

  void check_b() {
    for (unsigned int i = 8; i < 16; i++) {
      if (coordinates[i] == "B%d", i) {
        true_check_b[i-8] = 1;
      } else {
        true_check_b[i-8] = 0;
      }
    }
  }

  void check_g() {
    for (unsigned int i = 16; i < 24; i++) {
      if (coordinates[i] == "G%d", i) {
        true_check_g[i-16] = 1;
      } else {
        true_check_g[i-16] = 0;
      }
    }
  }

  void check_h() {
    for (unsigned int i = 24; i < 32; i++) {
      if (coordinates[i] == "H%d", i) {
        true_check_h[i-24] = 1;
      } else {
        true_check_h[i-24] = 0;
      }
    }
  }
  public:
    String coordinates[32];
  Board(String x[32]);
  ~Board();

  boolean check_to_initalize() {
    for (auto && i: true_check_a) {
      if (i == 0) {
        return false;
      }
    }
    for (auto && j: true_check_b) {
      if (j == 0) {
        return false;
      }
    }
    for (auto && y: true_check_g) {
      if (y == 0) {
        return false;
      }
    }
    for (auto && z: true_check_h) {
      if (z == 0) {
        return false;
      }
    }
    return true;
  }

  void set_board(String x[32]) {
    for (unsigned int i = 0; i < 32; i++) {
      coordinates[i] = x[i];
    }
  }

  void get_board(String x[32]) {
    for (unsigned int i = 0; i < 32; i++) {
      Serial.println(coordinates[i]);
    }
  }
};

Board::Board(String x[32]) {
  for (unsigned int i = 0; i < 32; i++) {
    coordinates[i] = x[i];
  }
}

Board::~Board() {}

#endif

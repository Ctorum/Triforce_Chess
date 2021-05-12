#ifndef BOARD_H_
#define BOARD_H_

class Board
{
public:
  String coordinates[32];
  Board(String x[32]);
  ~Board();

  void setBoard(String x[32])
  {
    for (unsigned int i = 0; i < 32; i++)
    {
      coordinates[i] = x[i];
    }
  }

  void getBoard(String x[32])
  {
    for (unsigned int i = 0; i < 32; i++)
    {
      Serial.println(coordinates[i]);
    }
  }
};

Board::Board(String x[32])
{
  for (unsigned int i = 0; i < 32; i++)
  {
    coordinates[i] = x[i];;
  }
}

Board::~Board()
{
}


#endif
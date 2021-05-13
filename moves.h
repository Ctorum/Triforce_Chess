#ifndef MOVES_H_
#define MOVES_H_

class Moves
{
public:
  String positions, AUX_positions, RAM_positions, moves;
  Moves(String pos);
  ~Moves();

  String setMoves()
  {
    for (unsigned int i = 0; i < 32; i++)
    {
      if (positions[i] == AUX_positions[i])
      {
        RAM_positions[i] = positions[i] + AUX_positions[i];
      }
      else
      {
        moves = positions[i] + AUX_positions[i];
      }  
    }
  }
};

Moves::Moves(String pos)
{
  positions = pos;
  AUX_positions = pos;
}

Moves::~Moves()
{
}

#endif
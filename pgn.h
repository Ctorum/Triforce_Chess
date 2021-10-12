#ifndef PGN_H_
#define PGN_H_

/* 
x - capture
K - king
Q - queen
R - rook
B - bishop
N - Knight
nothing - pawn
-------------
Algebraic name starts from a1 to h8
Kingside castling - O-O
Queenside castling - O-O-O
Pawn promotion - =
Checking move - +
Chekmating move - #
Comments - ;
Finish has 4 types of ending
  1. 1-0(White wins)
  2. 0-1(Black Wins)
  3. 1/2-1/2(Draw)
  4. *(Match in progress)
-------------
PGN notation template
  n. [W]Pa0(a0)xh8 [B]Pa0(a0)xh8 - Movement and Capture Template
  n. [W]O-O [B]O-O-O - Castling Template
  n. [W]Pa0(a0)+ [B]Pa0(a0)# - Check and Checkmate Template
  n. [W]a0= [B]h0= - Promotion Template
*/

class PGN {
  public:
    String match, RAM_match, plays, event, date, white, black, result;
  PGN(String e, String d, String w, String b, String r);
  ~PGN();

  String getPGN() {
    return match;
  }

  String setPGN(String p) {
    plays = p + " ";
    match = RAM_match + plays;
    RAM_match = match;
  }
};

PGN::PGN(String e, String d, String w, String b, String r) {
  event = e;
  date = d;
  white = w;
  black = b;
  result = r;
  match = "[Event \"%s\"]\n[Date \"%s\"]\n[White \"%s\"]\n[Black \"%s\"]\n[Result \"%s\"]\n", e, d, w, b, r;
  RAM_match = match;
}

PGN::~PGN() {}

#endif
#ifndef PGN_H_
#define PGN_H_

class PGN
{
public:
  String text, event, date, white, black, result;
  PGN(String e, String d, String w, String b, String r);
  ~PGN();
};

PGN::PGN(String e, String d, String w, String b, String r)
{
  event = e;
  date = d;
  white = w;
  black = b;
  result = r;
}

PGN::~PGN()
{
}


#endif
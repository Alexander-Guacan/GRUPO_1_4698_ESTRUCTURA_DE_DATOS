#ifndef BB
#define BB
#include"ClaseA.h"
class ClaseB
{    int b;
   public:
     friend int P(ClaseA);
     void defineB(int);
     int dameB(void);
};

#endif
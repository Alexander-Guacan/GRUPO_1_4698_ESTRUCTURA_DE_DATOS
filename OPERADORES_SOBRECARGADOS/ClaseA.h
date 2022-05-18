#ifndef AA
#define AA
#include<iostream>
class ClaseA
{    int a;
   public:
     friend int P(ClaseA);
     void defineA(int);
     int dameA(void);
};

#endif
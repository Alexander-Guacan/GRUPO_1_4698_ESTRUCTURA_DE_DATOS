#ifndef B_H
#define B_H
#include "Valor.h"

class B //agregado
{    
  int b;
  int cant;
  Valor m[20];
  
  public:
     B(void);
     void DefineB(int);
     int DameB(void);
     int DameCant(void);
     void Ingresa(int);
     int operator[](int);
};

#endif
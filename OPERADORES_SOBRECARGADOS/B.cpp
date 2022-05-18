#include "B.h"
#include <cstdio>
#include <conio.h>
#include "Valor.h"

B::B(void)
{    cant = 0;
}

void B::DefineB(int x)
{    b = x; 
}

int B::DameB(void)
{    return b; 
}

int B::DameCant(void)
{    return cant; 
}

void B::Ingresa(int x)
{    m[cant++].DefineValor(x); 
}

int B::operator[](int i)
{    return m[i].DameValor(); 
}
#include"ClaseB.h"
void ClaseB::defineB(int x)
{    b = x; 
}

int ClaseB::dameB(void)
{    return b; 
}
int P(ClaseA OA)
{    ClaseB Ob;
     Ob.defineB(2);
     return OA.a*Ob.b; 
}
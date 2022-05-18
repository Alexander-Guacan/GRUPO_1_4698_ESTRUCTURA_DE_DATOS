#include<iostream>
using namespace std;


class Quebrado
{    int numerador;
     int denominador;
   public:
     Quebrado (int,int);
     void DefineNum (int);
     void DefineDen (int);
     int DameNum (void);
     int DameDen (void);
     Quebrado operator+ (Quebrado &);
      // la referencia es sólo por eficiencia
};

Quebrado::Quebrado(int den,int num){
	denominador=den;
	numerador=num;
}

int Quebrado::DameDen(){
	return this->denominador;
}

int Quebrado::DameNum(){
	return this->numerador;
}

/*Quebrado operator + (Quebrado x, Quebrado y)
// aquí si van dos operadores
{    Quebrado queb;
     queb.DefineNum(x.DameNum() * y.DameDen() + y.DameNum() * x.DameDen());
     queb.DefineDen(x.DameDen() * y.DameDen());
     return queb;
};*/

Quebrado Quebrado::operator + (Quebrado &Q)
{   
	return Quebrado (numerador * Q.DameDen()+ Q.DameNum()* denominador , denominador * Q.DameDen());
}




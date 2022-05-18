
#include<iostream>
#include "Persona.h"
using namespace std;
Persona :: Persona(std::string s,int m){
	this->nombre=s;
	this->edad=m;
}
void Persona :: imprimirDatos(){
	cout<<"Nombre: "<<nombre<<"\nEdad: "<<edad<<endl;
}
Persona* Persona::operator->(){	
			return this;		
}


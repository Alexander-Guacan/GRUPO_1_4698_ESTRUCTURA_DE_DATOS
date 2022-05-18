/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Copiar ejercicios de operadores sobrecargados y por cada integrante del grupo generar un propio operador sobrecargado
 * Autor: Alexander David Guacán Rivera, Alison Paola Moncayo Achilchisa, Génesis Isabel Calapaqui Portilla, Ariel Alexander Jara Caiza
 * Fecha de creacion: 17/05/2022
 * Fecha de ultima modificación: 17/05/2022
 * Grupo: 1 y 17
 * Github: https://github.com/Alexander-Guacan/GRUPO_1_4698_ESTRUCTURA_DE_DATOS.git / https://github.com/Ariel2006/G17-ESTRUCTURA-DE-DATOS
 */

#include "Reloj.h"
#include "Vector.h"
#include "Persona.h"
#include "Cadena.h"
#include "Complejo.h"
#include "Cuadro.h"
#include "A.h"
#include "quebrado.h"
#include "B.h"
#include "ClaseA.h"
#include "Conjuntos.h"
#include "Cuadrado.h"
#include <iostream>
#include <iomanip>

int main() {
    // Ejercicio 1
    Reloj R(10,59,56);
    for (int i=0; i<10; i++, ++R)
    std::cout <<std::setw(4)<< R.Hora() <<std::setw(4)<< R.Minuto() 
         <<std::setw(4)<< R.Segundo() <<std:: endl;

    // Ejercicio 2
    Vector V1(10,20), V2(5,5);
     float p;

     p = V1*V2;

    std::cout << "P = " << p<< std::endl;

    // Ejercicio propio sobrecargando operador ->
    Persona obj("Genesis",32);
	obj.imprimirDatos();
	obj->imprimirDatos();

    // Ejercicio 3
    char mensaje1[]{"Hola "}, mensaje2[]{"Juan"};
    Cadena cadena1(mensaje1), cadena2(mensaje2);

    cadena1 + cadena2;

    std::cout << "Cadena1 + Cadena2 = " << cadena1.dameCadena();

    // Ejercicio 4
    Complejo comp1(5, 6), comp2(3, 4), comp3(2, 1);

    Complejo comp4 = comp1 + comp2 - comp3;

    printf("\nD = (%.2f + %.2f) + (%.2f + %.2f) - (%.2f + %.2f) = %.2f + %.2f",
           comp1.getParteReal(), comp1.getParteImaginaria(), comp2.getParteReal(), comp2.getParteImaginaria(),
           comp3.getParteReal(), comp3.getParteImaginaria(), comp4.getParteReal(), comp4.getParteImaginaria());
    
    // Ejercicio propio sobrecargando new
    int cantidadDeCuadros{};
    std::cout << "\nCantidad de cuadros a dibujar: ";
    std::cin >> cantidadDeCuadros;

    Cuadro cuadro;
    cuadro.dibujar(cantidadDeCuadros);

    // Ejercicio 5
    A A1(2), A2(3), A3(0);
    std ::cout << "Inicialmente : " << "\n";
    std ::cout << "A1 : " << A1.DameX() << "\n";
    std ::cout << "A2 : " << A2.DameX() << "\n";
    std ::cout << "\n";

    A3 = ++A1;
    std ::cout << "Como prefijo A3 = ++A1 : " << "\n";
    std ::cout << "A1 : " << A1.DameX() << "\n";
    std ::cout << "A3 : " << A3.DameX() << "\n";

    A3 = A2++;
    std ::cout << "\n";
    std::cout << "Como sufijo A3 = A2++: " << "\n";
    std ::cout << "A2 : " << A2.DameX() << "\n";
    std ::cout << "A3 : " << A3.DameX() << "\n";

    // Ejercicio 6
    Quebrado quebrado1(2,3), quebrado2(5,6), quebrado3(0,0);
    quebrado3 = quebrado1 + quebrado2;
    cout << quebrado3.DameNum() << "/" << quebrado3.DameDen() << std::endl;

    // Ejercicio 7
    ClaseA Objeto;
    Objeto.defineA(3);
    std::cout << P(Objeto) << std::endl;

    // Ejercicio sobrecargando operador -
    ComplejoTemplate<int> complejoTemplateA(1,3),complejoTemplateB(2,4);
	ComplejoTemplate<int> complejoTemplateC;
	int x,y;
	cout <<" suma de complejos "<<endl;
	complejoTemplateC=complejoTemplateA+complejoTemplateB;
	cout<<complejoTemplateC.getReal()<<"  +  "<<complejoTemplateC.getImg()<<"  i "<< endl;
	complejoTemplateC.setImg(0);
	complejoTemplateC.setReal(0);
	cout <<" resta de complejos "<<endl;
	complejoTemplateC=complejoTemplateA-complejoTemplateB;
	cout<<complejoTemplateC.getReal()<<"  +  "<<complejoTemplateC.getImg()<<"  i "<< endl;
	cin.ignore();
	system("pause");

    // Ejercicio 8
    B objetoB;

     std :: cout << "Ingrese datos :" << "\n";
     while (1)
     {    int p;
          std :: cin >> p;
          if (p<=0) break;
          objetoB.Ingresa(p);
     }
     std :: cout << "Datos leidos :" << "\n";
     for (int i=0; i<objetoB.DameCant(); i++)
     std :: cout << objetoB[i] << "\n";

    // Ejercicio sobrecargando operador +
    Cuadrado cuadrado1,cuadrado2,cuadrado3;

    cuadrado1.leer();
    cuadrado1.imprimeArea();
    cuadrado1.imprimePerimetro();

    std::cout << std::endl << std::endl;

    cuadrado2.leer();
    cuadrado2.imprimeArea();
    cuadrado2.imprimePerimetro();

    cuadrado3 = cuadrado1 + cuadrado2;
    std::cout << "\nSuma de area y perimetro:" << std::endl;
    cuadrado3.imprimeArea();
    cuadrado3.imprimePerimetro();

    return 0;
}

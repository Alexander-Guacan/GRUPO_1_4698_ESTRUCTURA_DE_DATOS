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
    system("cls");
    std::cout << "\n EJERCICIO 1: RELOJ\n";

    Reloj R(10, 59, 56);

    for (int i = 0; i < 10; i++, ++R)
        std::cout << std::setw(4) << R.Hora() << std::setw(4) << R.Minuto()
                  << std::setw(4) << R.Segundo() << std::endl;

    system("pause");

    // Ejercicio 2
    system("cls");
    std::cout << "\n EJERCICIO 2: PRODUCTO PUNTO DE VECTORES\n";

    Vector V1(10, 20), V2(5, 5);
    float p = V1 * V2;

    std::cout << "(" << V1.DameX() << ", " << V1.DameY() << ") * "
              << "(" << V2.DameX() << ", " << V2.DameY() << ")"
              << " = " << p << std::endl;

    system("pause");

    // Ejercicio propio sobrecargando operador ->
    system("cls");
    std::cout << "\n EJERCICIO DEL GRUPO SOBRECARGANDO OPERADOR ->\n";
    std::cout << "\nInstancia de objeto: Persona obj('Genesis', 32)\n";

    Persona obj("Genesis", 32);

    std::cout << "\nAccediendo a metodo: obj.imprimirDatos()\n";

    obj.imprimirDatos();

    std::cout << "\nAccediendo a metodo: obj->imprimirDatos()\n";

    obj->imprimirDatos();

    std::cout << '\n';
    system("pause");

    // Ejercicio 3
    system("cls");
    std::cout << "\n EJERCICIO 3: Concatenacion de cadenas\n";

    char mensaje1[]{"Hola "}, mensaje2[]{"Juan"};
    Cadena cadena1(mensaje1), cadena2(mensaje2);

    cadena1 + cadena2;

    std::cout << "\nCadena1{'Hola '} + Cadena2{'Juan'} = " << cadena1.dameCadena() << '\n';

    system("pause");

    // Ejercicio 4
    system("cls");
    std::cout << "\n EJERCICIO 4: Sumatoria de numeros complejos\n";

    Complejo comp1(5, 6), comp2(3, 4), comp3(2, 1);

    Complejo comp4 = comp1 + comp2 - comp3;

    printf("\n(%.2f + %.2fi) + (%.2f + %.2fi) - (%.2f + %.2fi) = %.2f + %.2fi\n",
           comp1.getParteReal(), comp1.getParteImaginaria(), comp2.getParteReal(), comp2.getParteImaginaria(),
           comp3.getParteReal(), comp3.getParteImaginaria(), comp4.getParteReal(), comp4.getParteImaginaria());

    system("pause");

    // Ejercicio propio sobrecargando new
    system("cls");
    std::cout << "\n EJERCICIO DEL GRUPO SOBRECARGANDO OPERADOR new\n";

    std::cout << "\nIngrese cantidad de cuadros a dibujar: ";

    int cantidadDeCuadros{};
    std::cin >> cantidadDeCuadros;

    Cuadro cuadro;
    cuadro.dibujar(cantidadDeCuadros);

    std::cout << '\n';
    system("pause");

    // Ejercicio 5
    system("cls");
    std::cout << "\n EJERCICIO 5: sobrecarga de operador ++ como prefijo y sufijo\n";

    A A1(2), A2(3), A3(0);

    std::cout << "Inicialmente :\n"
              << "A1 : " << A1.DameX() << "\n"
              << "A2 : " << A2.DameX() << "\n\n";

    A3 = ++A1;
    std::cout << "Como prefijo A3 = ++A1 :\n"
              << "A1 : " << A1.DameX() << "\n"
              << "A3 : " << A3.DameX() << "\n\n";

    A3 = A2++;
    std::cout << "Como sufijo A3 = A2++:\n"
              << "A2 : " << A2.DameX() << "\n"
              << "A3 : " << A3.DameX() << "\n\n";
    system("pause");

    // Ejercicio 6
    system("cls");
    std::cout << "\n EJERCICIO 6: sumatoria de fracciones\n";
    Quebrado quebrado1(2, 3), quebrado2(5, 6), quebrado3(0, 0);
    quebrado3 = quebrado1 + quebrado2;
    std::cout << quebrado1.DameNum() << "/" << quebrado1.DameDen() << " + "
              << quebrado2.DameNum() << "/" << quebrado2.DameDen() << " = "
              << quebrado3.DameNum() << "/" << quebrado3.DameDen() << std::endl;
    system("pause");

    // Ejercicio 7
    system("cls");
    std::cout << "\n EJERCICIO 7: uso de funcion friend\n";

    ClaseA Objeto;
    Objeto.defineA(3);

    std::cout << P(Objeto) << std::endl;

    system("pause");

    // Ejercicio sobrecargando operador -
    system("cls");
    std::cout << "\n EJERCICIO DEL GRUPO SOBRECARGANDO OPERADOR - y +\n";

    ComplejoTemplate<int> complejoTemplateA(1, 3), complejoTemplateB(2, 4);
    ComplejoTemplate<int> complejoTemplateC;

    std::cout << "Suma de complejos " << std::endl;

    complejoTemplateC = complejoTemplateA + complejoTemplateB;

    std::cout << "(" << complejoTemplateA.getReal() << " + " << complejoTemplateA.getImg() << "i)"
              << " + (" << complejoTemplateB.getReal() << " + " << complejoTemplateB.getImg() << "i) = "
              << "(" << complejoTemplateC.getReal() << " + " << complejoTemplateC.getImg() << " i)" << std::endl;

    complejoTemplateC.setImg(0);
    complejoTemplateC.setReal(0);

    std::cout << "Resta de complejos " << std::endl;

    complejoTemplateC = complejoTemplateA - complejoTemplateB;

    std::cout << "(" << complejoTemplateA.getReal() << " + " << complejoTemplateA.getImg() << "i)"
              << " - (" << complejoTemplateB.getReal() << " + " << complejoTemplateB.getImg() << "i) = "
              << "(" << complejoTemplateC.getReal() << " + " << complejoTemplateC.getImg() << " i)" << "\n\n";

    system("pause");

    // Ejercicio 8
    system("cls");
    std::cout << "\n EJERCICIO 8\n";

    B objetoB;

    std::cout << "Ingrese numeros (ingrese 0 para detener el ingreso):"
               << "\n";
    while (1)
    {
        int p;
        std ::cin >> p;
        if (p <= 0)
            break;
        objetoB.Ingresa(p);
    }

    std ::cout << "Datos leidos :\n";

    for (int i = 0; i < objetoB.DameCant(); i++)
        std::cout << objetoB[i] << "\n";

    system("pause");

    // Ejercicio sobrecargando operador +
    system("cls");
    std::cout << "\n EJERCICIO DEL GRUPO SOBRECARGANDO OPERADOR +\n";
    Cuadrado cuadrado1, cuadrado2, cuadrado3;

    cuadrado1.leer();
    cuadrado1.imprimeArea();
    cuadrado1.imprimePerimetro();

    std::cout << "\n";

    cuadrado2.leer();
    cuadrado2.imprimeArea();
    cuadrado2.imprimePerimetro();

    cuadrado3 = cuadrado1 + cuadrado2;

    std::cout << "\nSuma de area y perimetro:\n\n";
    cuadrado3.imprimeArea();
    cuadrado3.imprimePerimetro();

    std::cout << '\n';

    system("pause");

    return 0;
}

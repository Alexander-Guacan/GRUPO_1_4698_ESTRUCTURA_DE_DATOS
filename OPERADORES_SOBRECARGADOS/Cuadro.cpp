#include "Cuadro.h"
#include "Consola.h"

void Cuadro::dibujar(int cantidadDeCuadros) {
    Consola consola;
    system("cls");
    consola.ubicarCursor(1, 20);

    for (int i{}; i < cantidadDeCuadros; i++) {
        int longitudMensaje = printf("Ingrese coordenada con el siguiente formato x, y: ");

        int x{}, y{};
        scanf("%d%*c%*c%d", &x, &y);

        Cuadro *cuadro = new (x, y) Cuadro;

        consola.ubicarCursor(longitudMensaje, 20);
        for (int i{}; i < 10; i++)
            printf(" ");

        consola.ubicarCursor(1, 20);
    }
}

void *Cuadro::operator new(std::size_t size, short x, short y) {
    const char ICONO = 254;
    void *puntero = ::operator new(size);

    Consola consola;
    consola.ubicarCursor(x, y);
    printf("%c", ICONO);

    return puntero;
}
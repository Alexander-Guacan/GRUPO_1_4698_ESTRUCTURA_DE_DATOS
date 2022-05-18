#include "Consola.h"
#include <windows.h>

void Consola::ubicarCursor(short x, short y) {
    HANDLE identificadorDeConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD posicion{x, y};
    SetConsoleCursorPosition(identificadorDeConsola, posicion);
}
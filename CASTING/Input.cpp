#include "Input.h"
#include <cstdio>
#include <conio.h>

char *Input::ingresarDatoEntero(const char* mensaje) {
    const int ENTER_KEY = 13;
    const int BACKSPACE_KEY = 8;
    const int DELETE_KEY = 127;

    printf("%s", mensaje);

    char *dato = new char[10];
    char caracterIngresado;

    int i{};
    while ((caracterIngresado = getch()) != ENTER_KEY) {
        if (caracterIngresado >= '0' && caracterIngresado <= '9') {
            printf("%c", caracterIngresado);
            dato[i++] = caracterIngresado;
        } else if (caracterIngresado == BACKSPACE_KEY) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        }
    }

    dato[i] = '\0';

    return dato;
}

char *Input::ingresarDatoReal(const char *mensaje) {
    const int ENTER_KEY = 13;
    const int BACKSPACE_KEY = 8;
    const int DELETE_KEY = 127;

    printf("%s", mensaje);

    char *dato = new char[10];
    char caracterIngresado;

    int i{};
    bool haIngresadoPunto{false};
    while ((caracterIngresado = getch()) != ENTER_KEY) {
        if (caracterIngresado >= '0' && caracterIngresado <= '9') {
            printf("%c", caracterIngresado);
            dato[i++] = caracterIngresado;
        } else if(caracterIngresado == '.' && !haIngresadoPunto) {
            printf("%c", caracterIngresado);
            dato[i++] = caracterIngresado;
            haIngresadoPunto = true;
        } else if (caracterIngresado == BACKSPACE_KEY) {
            if (i > 0) {
                i--;
                if (dato[i] == '.') {
                    haIngresadoPunto = false;
                }
                printf("\b \b");
            }
        }
    }

    dato[i] = '\0';

    return dato;
}
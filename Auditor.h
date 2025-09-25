#include <iostream>

using namespace System;
using namespace std;

class Auditor {
private:
    int x, y;

    // --- ¡USAMOS TU DISEÑO! ---
    // Definimos las dimensiones basadas en tu array
    static const int ancho = 7;
    static const int alto = 3;

    // Tu array de caracteres para el personaje
    char forma[alto][ancho + 1] = { // +1 para el caracter nulo '\0' de las cadenas de texto
        "\xBA o/-\\",
        "\xC5/|)O(",
        " / \\-/"
    };

public:
    Auditor(int _x, int _y) {
        x = _x;
        y = _y;
    }

    void dibujar() {
        // Un bucle anidado para dibujar cada caracter de tu diseño
        for (int i = 0; i < alto; i++) {
            for (int j = 0; j < ancho; j++) {
                // No dibujamos los espacios en blanco para no generar "flicker"
                if (forma[i][j] != ' ') {
                    Console::SetCursorPosition(x + j, y + i);
                    cout << forma[i][j];
                }
            }
        }
    }

    void borrar() {
        // Un bucle idéntico para borrar el personaje, dibujando espacios
        for (int i = 0; i < alto; i++) {
            for (int j = 0; j < ancho; j++) {
                Console::SetCursorPosition(x + j, y + i);
                cout << " ";
            }
        }   
    }

    void mover(char tecla) {
        borrar(); // 1. Borramos la posición antigua

        // 2. Actualizamos las coordenadas
        switch (tecla) {
        case 'w': case 72: y--; break;
        case 's': case 80: y++; break;
        case 'a': case 75: x--; break;
        case 'd': case 77: x++; break;
        }

        dibujar(); // 3. Dibujamos en la nueva posición
    }
};

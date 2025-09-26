// Auditor.h
#pragma once // Es buena práctica usar pragma once en lugar de ifndef en VS
#include <iostream>

using namespace System;
using namespace std;

class Auditor {
private:
    int x, y;
    static const int ancho = 7;
    static const int alto = 3;
    char forma[alto][ancho + 1] = {
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
        for (int i = 0; i < alto; i++) {
            for (int j = 0; j < ancho; j++) {
                if (forma[i][j] != ' ') {
                    Console::SetCursorPosition(x + j, y + i);
                    cout << forma[i][j];
                }
            }
        }
    }

    void borrar() {
        for (int i = 0; i < alto; i++) {
            for (int j = 0; j < ancho; j++) {
                Console::SetCursorPosition(x + j, y + i);
                cout << " ";
            }
        }
    }

    // Mover AHORA solo actualiza las coordenadas. No borra ni dibuja.
    void mover(char tecla) {
        if (tecla == 'a' || tecla == 75) x--;
        if (tecla == 'd' || tecla == 77) x++;
        if (tecla == 'w' || tecla == 72) y--;
        if (tecla == 's' || tecla == 80) y++;
    }
};
// Dialogo.h
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

// Usamos los namespaces que te son familiares
using namespace System;
using namespace std;

class Dialogo {
private:
    int x, y, ancho, alto;

    // Método privado para dibujar el marco del diálogo
    void dibujarMarco() {
        Console::SetCursorPosition(x, y); cout << (char)201; // ╔
        for (int i = 0; i < ancho - 2; i++) cout << (char)205; // ═
        cout << (char)187; // ╗

        for (int i = 1; i < alto - 1; i++) {
            Console::SetCursorPosition(x, y + i); cout << (char)186; // ║
            Console::SetCursorPosition(x + ancho - 1, y + i); cout << (char)186; // ║
        }

        Console::SetCursorPosition(x, y + alto - 1); cout << (char)200; // ╚
        for (int i = 0; i < ancho - 2; i++) cout << (char)205; // ═
        cout << (char)188; // ╝
    }

    void escribir(string texto) {
        int maxAncho = ancho - 4;
        vector<string> lineas;
        size_t i = 0;
        while (i < texto.length()) {
            int chars = 0, lastSpace = -1;
            while (chars < maxAncho && i + chars < texto.length()) {
                if (texto[i + chars] == ' ') lastSpace = chars;
                if (texto[i + chars] == '\n') break;
                chars++;
            }
            int corte = (chars == maxAncho && lastSpace != -1) ? lastSpace : chars;
            lineas.push_back(texto.substr(i, corte));
            i += corte;
            if (i < texto.length() && texto[i] == ' ') i++;
            if (i < texto.length() && texto[i] == '\n') i++;
        }
        // Ahora solo recorres el vector y escribes cada línea
        for (int fila = 0; fila < lineas.size() && fila < alto - 4; fila++) {
            Console::SetCursorPosition(x + 2, y + 2 + fila);
            for (char c : lineas[fila]) {
                cout << c;
                Sleep(30);
            }
        }
    }

public:
    // Constructor: Define la posición y tamaño del cuadro
    Dialogo(int _x, int _y, int _ancho, int _alto) {
        x = _x; y = _y;
        ancho = _ancho; alto = _alto;
    }

    // Muestra un único mensaje y espera una tecla
    void mostrarMensaje(string mensaje) {
        dibujarMarco();
        limpiarCuadro(); // Limpia el área interna antes de escribir
        Console::SetCursorPosition(x + 2, y + 2);
        escribir(mensaje);
        _getch();
        borrarCuadro(); // Borra el cuadro después de mostrar el mensaje
    }
    void limpiarCuadro() {
        for (int i = 1; i < alto - 1; i++) {
            Console::SetCursorPosition(x + 1, y + i);
            for (int j = 1; j < ancho - 1; j++) {
                cout << " ";
            }
        }
    }
    void borrarCuadro() {
        for (int i = 0; i < alto; i++) {
            Console::SetCursorPosition(x, y + i);
            for (int j = 0; j < ancho; j++) {
                cout << " ";
            }
        }
    }

    // Muestra una pregunta con dos opciones y devuelve la elección del jugador
    int mostrarPregunta(string pregunta, string op1, string op2) {
        dibujarMarco();
        Console::SetCursorPosition(x + 2, y + 2);
        escribir(pregunta);

        Console::SetCursorPosition(x + 4, y + 5);
        cout << "1. " << op1;
        Console::SetCursorPosition(x + 4, y + 6);
        cout << "2. " << op2;

        char seleccion = '0';
        
        while (seleccion != '1' && seleccion != '2') {
            seleccion = _getch();
        }
        return seleccion - '0'; // Devuelve 1 o 2
    }
};
#pragma once
#include "JUEGO.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace System;
using namespace std;

class MenuJuego {
public:
    int opcion;
    bool continuar;

    MenuJuego() {
        opcion = 1;
        continuar = true;
    }

    void PosicionarCursor(int x, int y) {
        Console::SetCursorPosition(x, y);
    }

    void Jugar() {
        // 1. Se crea el objeto Juego.
        Juego miPartida;
        // 2. Se llama a su método para iniciar la partida (diálogo + bucle).
        miPartida.iniciarPartida();
        // 3. Cuando el juego termina, esta función termina, y el control
        //    regresa al bucle del menú en Gestionar().
    }

    void MostrarInstrucciones() {
        Console::Clear();
        PosicionarCursor(10, 5);
        cout << "--- INSTRUCCIONES ---";
        PosicionarCursor(10, 12);
        cout << "Presiona cualquier tecla para volver al menu...";
        _getch();
    }

    void MostrarCreditos() {
        Console::Clear();
        PosicionarCursor(10, 5);
        cout << "--- CREDITOS ---";
        PosicionarCursor(10, 12);
        cout << "Presiona cualquier tecla para volver al menu...";
        _getch();
    }

    void Gestionar() {
        const int ARRIBA = 72;
        const int ABAJO = 80;
        const int ENTER = 13;
        char tecla;
        Console::Clear();
        do {
            
            Console::CursorVisible = false;

            PosicionarCursor(38, 6);  cout << "   _____                           ";
            PosicionarCursor(38, 7);  cout << "  /     \\   ____   ____  __ __     ";
            PosicionarCursor(38, 8);  cout << " /  \\ /  \\_/ __ \\ /    \\|  |  \\    ";
            PosicionarCursor(38, 9);  cout << "/    Y    \\  ___/|   |  \\  |  /    ";
            PosicionarCursor(38, 10); cout << "\\____|__  /\\___  >___|  /____/     ";
            PosicionarCursor(38, 11); cout << "        \\/     \\/     \\/           ";

            PosicionarCursor(36, 16); cout << string(45, (char(178)));

            PosicionarCursor(43, 19); cout << (opcion == 1 ? " >> " : "    ") << "Jugar";
            PosicionarCursor(43, 21); cout << (opcion == 2 ? " >> " : "    ") << "Instrucciones";
            PosicionarCursor(43, 23); cout << (opcion == 3 ? " >> " : "    ") << "Creditos";
            PosicionarCursor(43, 25); cout << (opcion == 4 ? " >> " : "    ") << "Salir";

            PosicionarCursor(36, 30); cout << string(45, (char(178)));

            tecla = _getch();

            switch (tecla) {
            case ARRIBA:
            case 'w':
                opcion--;
                if (opcion < 1) opcion = 4;
                break;
            case ABAJO:
            case 's':
                opcion++;
                if (opcion > 4) opcion = 1;
                break;
            case ENTER:
                switch (opcion) {
                case 1: Jugar(); break;
                case 2: MostrarInstrucciones(); break;
                case 3: MostrarCreditos(); break;
                case 4: continuar = false; break;
                }
                Console::Clear();
                break;
            }
        } while (continuar);
    }
};
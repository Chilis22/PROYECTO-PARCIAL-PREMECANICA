#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Tutor.h" // ¡Incluimos al Tutor!
#include "Auditor.h"
#include "Mundos.h"
using namespace System;
using namespace std;

class Juego {
private:
    Tutor* miTutor;
    Auditor* miAuditor; // ¡Creamos el espacio para nuestro jugador!
    bool juegoActivo;
    string pista; // Para guardar la pista del Tutor
    Mundo* MiMundo1;

public:
    // Constructor: Crea los objetos necesarios
    Juego() {
        miTutor = new Tutor();
        // Creamos al Auditor en una posición inicial
        miAuditor = new Auditor(10, 5);
        juegoActivo = true;
        pista = ""; // La pista empieza vacía
        MiMundo1 = new Mundo();
    }

    // Destructor: Libera la memoria
    ~Juego() {
        delete miTutor;
        delete miAuditor; // Liberamos la memoria del auditor
		delete MiMundo1;
    }

    void iniciarPartida() {
        // --- PASO 1: Premecánica ---
       // int resultadoDialogo = miTutor->realizarDialogoMundoIA();

        // --- PASO 2: Guardamos el resultado del diálogo ---
       // if (resultadoDialogo == 1) {
           // pista = "Pista: No todas las reglas estan hechas para ser seguidas.";
      //  }

        // --- PASO 3: Bucle Principal del Juego ---
        buclePrincipal();
    }

private: // Métodos internos del juego
    void buclePrincipal() {

        char tecla = 0;
        //dibujamos el primer mundo
        

        // El bucle principal ahora maneja el movimiento y el dibujo
        Console::Clear();
        MiMundo1->dibujar();
        miAuditor->dibujar();
        while (juegoActivo) {

            // 1. Procesar Input
            if (_kbhit()) {
                tecla = _getch();
                if (tecla == 27) { // Tecla ESC para salir
                    juegoActivo = false;
                }
                // Llamamos al método mover del propio Auditor
                miAuditor->mover(tecla);
            }

            // 2. Dibujar todo en pantalla
            
            miAuditor->dibujar();
            Sleep(50);
        }
    }

    
};

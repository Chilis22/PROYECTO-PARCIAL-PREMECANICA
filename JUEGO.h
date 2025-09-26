// JUEGO.h
#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Auditor.h"
#include "Mundos.h"
#include "Dialogo.h" // ¡Incluimos nuestra nueva clase Dialogo!

using namespace System;
using namespace std;

class Juego {
private:
    Auditor* miAuditor;
    Mundo* miMundo;
    Dialogo* miDialogo; // Usamos un objeto Dialogo, no Tutor
    bool juegoActivo;
    string pista;

public:
    Juego() {
        miAuditor = new Auditor(10, 35);
        miMundo = new Mundo();
        // Creamos el cuadro de diálogo en una posición y tamaño definidos
        miDialogo = new Dialogo(25, 8, 70, 15);
        juegoActivo = true;
        pista = "";
    }

    ~Juego() {
        delete miAuditor;
        delete miMundo;
        delete miDialogo;
    }

    void iniciarPartida() {
        Console::Clear();
        miMundo->dibujar(); // Dibuja el escenario
        miAuditor->dibujar(); // Dibuja al auditor

        // --- Ejecuta la premecánica usando la nueva clase Dialogo ---
      /*  int resp = miDialogo->mostrarPregunta("Auditor, has entrado al Mundo IA. ¿Confiaras en la logica o en la creatividad?",
            "La logica es el unico camino.",
            "A veces, la solucion no esta en los datos.");

        if (resp == 2) {
            pista = "Pista: No todas las reglas estan hechas para ser seguidas.";
		}
		else {
			pista = "Pista: La logica puede ser un arma de doble filo.";
		}
        */
        // --- Comienza el bucle de juego interactivo ---
        buclePrincipal();
    }

private:
    void buclePrincipal() {
        char tecla = 0;
        int frame = 0;
        while (juegoActivo) {
            
            miMundo->dibujarArteAnimado(10, 5, frame);

            if (_kbhit()) {
                tecla = _getch();
                if (tecla == 27) { // ESC para salir
                    juegoActivo = false;
                }
                else {
                    miAuditor->borrar();
                    miAuditor->mover(tecla);
                    miAuditor->dibujar();
                }
            }
            frame++;
            Sleep(120); // Ajusta la velocidad de animación
        }
    }
};
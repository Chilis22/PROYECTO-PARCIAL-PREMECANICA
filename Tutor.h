#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

// No necesitamos la clase Menu aquí, así que mantenemos los archivos separados
using namespace System;
using namespace std;
class Tutor {
private:
    // Método privado para mostrar texto con efecto de máquina de escribir
    void escribir(string texto) {
        for (char c : texto) {
            cout << c;
            Sleep(30); // Pequeña pausa entre cada letra
        }
        cout << endl;
    }

    // Método privado para obtener la respuesta del jugador
    char obtenerRespuesta(string op1, string op2) {
        Console::SetCursorPosition(12, 12);
        cout << "1. " << op1;
        Console::SetCursorPosition(12, 13);
        cout << "2. " << op2;
        return _getch();
    }

public:
    // El método principal ahora devuelve un "bonificador" o "penalizador"
    // 0 = Sin efecto, 1 = Pista, -1 = Hándicap
    int realizarDialogoMundoIA() {
        Console::Clear();
        Console::SetCursorPosition(10, 5);
        escribir("[TUTOR]: Sistema IA detectado. La eficiencia ha generado rigidez.");

        Console::SetCursorPosition(10, 7);
        escribir("Dime, Auditor, ante un muro infranqueable, ¿qué haces?");
        char resp1 = obtenerRespuesta("Analizo su estructura buscando un punto debil logico.", "Busco una forma de rodearlo, aunque parezca imposible.");

        int puntuacionCreatividad = 0;
        if (resp1 == '2') puntuacionCreatividad++;

        Console::SetCursorPosition(10, 15);
        escribir("[TUTOR]: Entendido. Ahora, un proceso se repite en un bucle sin fin. ¿La solucion?");
        char resp2 = obtenerRespuesta("Optimizar el bucle para que termine.", "Romper el bucle, aunque cause inestabilidad.");

        if (resp2 == '2') puntuacionCreatividad++;

        Console::SetCursorPosition(10, 20);
        if (puntuacionCreatividad == 2) {
            escribir("[TUTOR]: Tu enfoque es... inesperado. Audaz. Te sera util aqui. Recuerda: no todas las reglas estan hechas para ser seguidas.");
            _getch();
            return 1; // Devuelve "Pista"
        }
        else if (puntuacionCreatividad == 1) {
            escribir("[TUTOR]: Veo una mezcla de logica y creatividad. Interesante. Procede con cautela.");
            _getch();
            return 0; // Sin efecto
        }
        else {
            escribir("[TUTOR]: Tu logica es impecable, pero este lugar no siempre la respeta. Ten cuidado.");
            _getch();
            return 0; // Sin efecto
        }
    }
};
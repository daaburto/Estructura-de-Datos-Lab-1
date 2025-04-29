#include <iostream>
#include <stack>
#include "heroe.h"

using namespace std;

/*
Implementación del problema usando el ADT Stack.
Se eligió trabajar con un Stack porque consideramos que las operaciones que tiene son suficientes para
satisfacer el problema planteado.
En específico, para los CANOs es más fácil trabajar con los métodos de un Stack que con los del Queue, ya que,
a diferencia de un Queue, el Stack ingresa los nuevos esbirros desde arriba, dejándolos encima del esbirro
anterior y listos para el siguiente ataque, mientras que en Queue tendríamos que dar la vuelta a la cola para
colocar a los nuevos esbirros en la cima.
*/
int main() {
    int vida_mechon, cant_esbirros;
    cin >> vida_mechon;
    cin >> cant_esbirros;

    // Crear arrays según la cantidad de esbirros que hay
    int vida_esbirro[cant_esbirros];
    int ataque_esbirro[cant_esbirros];
    bool esbirro_cano[cant_esbirros];

    // Leer vida y añadirlo a vida_esbirro
    for (int i = 0; i < cant_esbirros; i++) {
        cin >> vida_esbirro[i];
    }

    // Leer ataque y añadirlo a ataque_esbirro
    for (int i = 0; i < cant_esbirros; i++) {
        cin >> ataque_esbirro[i];
    }

    // Leer si el esbirro es CANO y añadirlo a esbirro_cano
    for (int i = 0; i < cant_esbirros; i++) {
        int temp;
        cin >> temp;
        esbirro_cano[i] = (temp == 1);
    }

    // Inicializar clases
    Heroe mechon(vida_mechon);
    stack<Esbirro> esbirros; // stack que va a contener a los esbirros
    for (int i = cant_esbirros - 1; i >= 0; i--) {
        esbirros.push(Esbirro(vida_esbirro[i], ataque_esbirro[i], esbirro_cano[i]));
    }

    // Simulación del enfrentamiento
    while (!esbirros.empty() && !mechon.estaMuerto()) {
        Esbirro &esbirro_actual = esbirros.top();
        mechon.atacar(esbirro_actual);

        // Verifica si el esbirro está muerto para quitarlo del deque
        if (esbirro_actual.estaMuerto()) {
            mechon.eliminarEsbirro();
            esbirros.pop();
        }

        // Si aún quedan esbirros, verifica si el esbirro CANO puede separarse
        if (!esbirros.empty()) {
            if (esbirro_actual.getEsCano() && esbirro_actual.getAtaquesRecibidos() == 2) {
                Esbirro cano = esbirros.top();
                esbirros.pop();
                esbirros.push(cano.crearEsbirro());
                esbirros.push(cano.crearEsbirro());
            }
            // mechón recibe ataque del esbirro en la primera posición del deque
            mechon.recibirAtaque(esbirro_actual.getAtaque());
        }
    }

    cout << mechon.getDañoTotal() << endl;
    if (esbirros.empty()) {
        cout << "EZ pizi" << endl;
    }
    else
        cout << "RIP mechón" << endl;
    return 0;
}

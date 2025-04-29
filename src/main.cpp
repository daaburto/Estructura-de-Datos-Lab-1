#include <iostream>
#include <deque>
#include "heroe.h"

using namespace std;

int main() {
    int vida_mechon, cant_esbirros;
    // cout << "Vida del mechon:";
    cin >> vida_mechon;
    // cout << "Cantidad de esbirros contra el mechon:";
    cin >> cant_esbirros;

    // Crear arrays según la cantidad de esbirros que hay
    int vida_esbirro[cant_esbirros];
    int ataque_esbirro[cant_esbirros];
    bool esbirro_cano[cant_esbirros];

    // Leer vida y añadirlo a vida_esbirro
    // cout << "Vida de los esbirros:";
    for (int i = 0; i < cant_esbirros; i++) {
        cin >> vida_esbirro[i];
    }

    // Leer ataque y añadirlo a ataque_esbirro
    // cout << "Ataque de los esbirros:";
    for (int i = 0; i < cant_esbirros; i++) {
        cin >> ataque_esbirro[i];
    }

    // Leer si el esbirro es CANO y añadirlo a esbirro_cano
    // cout << "El esbirro es CANO?:";
    for (int i = 0; i < cant_esbirros; i++) {
        int temp;
        cin >> temp;
        esbirro_cano[i] = (temp == 1);
    }

    // Inicializar clases
    Heroe mechon(vida_mechon);
    deque<Esbirro> esbirros; // deque que va a contener a los esbirros
    for (int i = 0; i < cant_esbirros; i++) {
        esbirros.push_back(Esbirro(vida_esbirro[i], ataque_esbirro[i], esbirro_cano[i]));
    }

    // Simulación del enfrentamiento
    while (!esbirros.empty() && !mechon.estaMuerto())
    {
        Esbirro &esbirro_actual = esbirros.front();
        mechon.atacar(esbirro_actual);
        if (esbirro_actual.estaMuerto()) {
            mechon.eliminarEsbirro();
            esbirros.pop_front();
        }

        // Si aún quedan esbirros, Verifica si el esbirro CANO puede separarse
        if (!esbirros.empty()) {
            if (esbirro_actual.getEsCano() && esbirro_actual.getAtaquesRecibidos() == 2) {
                Esbirro cano = esbirros.front();
                esbirros.pop_front();
                esbirros.push_front(cano.crearEsbirro());
                esbirros.push_front(cano.crearEsbirro());
            }

            mechon.recibirAtaque(esbirro_actual.getAtaque());
        }
    }

    cout << "Daño total = " << mechon.getDañoTotal() << endl;
    if (esbirros.empty()) {
        cout << "EZ pizi" << endl;
    }
    else
        cout << "RIP mechón" << endl;

    cout << "Vida del mechon: " << mechon.getVida();
    cout << "\n Ataque del mechon: " << mechon.getAtaque();
    cout << "\n Esbirros faltantes: " << esbirros.size() << endl;

    return 0;
}

#ifndef HEROE_H
#define HEROE_H
#include "esbirro.h"
using namespace std;

class Heroe {
private:
    int vida;
    int ataque;
    int esbirros_eliminados;
    int daño_total;

public:
    // Constructor
    Heroe(int vida) {
        this->vida = vida;
        this->ataque = 2;
        this->esbirros_eliminados = 0;
        this->daño_total = 0;
    }

    int getVida() {
        return vida;
    }

    int getAtaque() {
        return ataque;
    }

    int getDañoTotal() {
        return daño_total;
    }

    // Reduce la vida del héroe según el valor del ataque recibido.
    void recibirAtaque(int daño) {
        vida = max(0, vida - daño); // evita vida negativa
    }

    bool estaMuerto() {
        return vida <= 0;
    }

    // Cuando el esbirro está muerto, se llama a esta función
    // si los esbirros eliminados son múltiplo de 5, se le aumenta
    // en uno el ataque del héroe
    void eliminarEsbirro() {
        esbirros_eliminados++;
        if (esbirros_eliminados % 5 == 0) {
            ataque++;
        }
    }

    // El héroe ataca a un esbirro, calcula el daño y lo suma al daño total.
    void atacar(Esbirro &esbirro) {
        int aux = esbirro.getVida();
        esbirro.recibirAtaque(ataque);
        daño_total += (aux - esbirro.getVida());
    }
};
#endif // HEROE_H

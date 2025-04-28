//
// Created by daaburto on 4/26/2025.
//

#ifndef HEROE_H
#define HEROE_H
#include "esbirro.h"
using namespace std;
class Heroe
{
private:
    int vida;
    int ataque;
    int esbirros_eliminados;
    int daño_total;

public:
    // Constructor
    Heroe(int vida)
    {
        this->vida = vida;
        this->ataque = 2;
        this->esbirros_eliminados = 0;
        this->daño_total = 0;
    }

    int getVida()
    {
        return vida;
    }
    int getAtaque()
    {
        return ataque;
    }
    int getDañoTotal()
    {
        return daño_total;
    }

    void recibirAtaque(int daño)
    {
        vida = max(0, vida - daño); // evita vida negativa
    }

    bool estaMuerto()
    {
        return vida <= 0;
    }

    void eliminarEsbirro()
    {
        esbirros_eliminados++;
        if (esbirros_eliminados % 5 == 0)
        {
            ataque++; // Mejora del arma +1
        }
    }

    void atacar(Esbirro &esbirro)
    {
        daño_total += ataque;
        esbirro.recibirAtaque(ataque);
    }
};
#endif // HEROE_H

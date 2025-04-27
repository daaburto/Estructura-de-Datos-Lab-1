//
// Created by daaburto on 4/26/2025.
//

#ifndef ESBIRRO_H
#define ESBIRRO_H
using namespace std;
class Esbirro {
private:
    int vida;
    int ataque;
    bool es_cano;
    int ataques_recibidos;

public:
    // Constructor
    Esbirro(int vida, int ataque, bool es_cano) {
        this->vida = vida;
        this->ataque = ataque;
        this->es_cano = es_cano;
        this->ataques_recibidos = 0;
    }


    int getVida() {
        return vida;
    }
    int getAtaque() {
        return ataque;
    }
    bool getEsCano() {
        return es_cano;
    }
    int getAtaquesRecibidos() {
        return ataques_recibidos;
    }


    void recibirAtaque(int ataque) {
        vida = max(0, vida - ataque); // Evita vida negativa
        ataques_recibidos++;
    }

    bool estaMuerto() {
        return vida <= 0;
    }

    void debeSpawnear() {
        if (es_cano && ataques_recibidos == 2 && !estaMuerto())
            crearEsbirro();
        crearEsbirro();
    }

    // Metodo para crear un esbirro (para cuando un cano se divide)
    Esbirro crearEsbirro() {
        return Esbirro(max(1, vida - 1), max(1, ataque - 1), false);
    }
};
#endif //ESBIRRO_H

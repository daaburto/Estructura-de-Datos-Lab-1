#include <iostream>
#include <deque>

#include "heroe.h"

using namespace std;
int main() {
    Esbirro test(5,2,1);
    cout << "Ataque esbirro: " <<test.getAtaque() << "\n";
    cout << "Vida esbirro: " << test.getVida() << "\n";
    cout << "Es cano?: " << test.getEsCano() << "\n";

    Heroe Juan(10);
    cout << "Ataque heroe: " << Juan.getAtaque() << "\n";
    cout << "Vida heroe: " << Juan.getVida() << "\n";

    Juan.atacar(test);
    cout << "Vida esbirro: " << test.getVida() << "\n";

    return 0;
}

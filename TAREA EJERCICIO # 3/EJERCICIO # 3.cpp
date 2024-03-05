#include <cstdlib>
#include <ctime>
#include <iostream> 

using namespace std;

class Jugador {
protected:
    int eleccion;
    int puntaje;

public:
    Jugador() : eleccion(0), puntaje(0) {}

    int getEleccion() const {
        return eleccion;
    }

    void setEleccion(int opcion) {
        eleccion = opcion;
    }

    int getPuntaje() const {
        return puntaje;
    }

    void setPuntaje(int nuevoPuntaje) {
        puntaje = nuevoPuntaje;
    }

    virtual void jugar() = 0;
};

class Piedra : public Jugador {
public:
    Piedra() {
        setEleccion(1);
    }

    void jugar() override {}
};

class Tijera : public Jugador {
public:
    Tijera() {
        setEleccion(2);
    }

    void jugar() override {}
};

class Papel : public Jugador {
public:
    Papel() {
        setEleccion(3);
    }

    void jugar() override {}
};

int main() {
    srand(time(0));

    int eleccionUsuario;
    cout << "Ingresa tu eleccion (1 - Piedra, 2 - Tijera, 3 - Papel): ";
    cin >> eleccionUsuario;

    Jugador* jugadorUsuario;

    if (eleccionUsuario == 1)
        jugadorUsuario = new Piedra();
    else if (eleccionUsuario == 2)
        jugadorUsuario = new Tijera();
    else
        jugadorUsuario = new Papel();

    Jugador* jugadorComputadora;

    int eleccionComputadora = rand() % 3 + 1;

    if (eleccionComputadora == 1)
        jugadorComputadora = new Piedra();
    else if (eleccionComputadora == 2)
        jugadorComputadora = new Tijera();
    else
        jugadorComputadora = new Papel();

    // Lógica del juego
    cout << "Eleccion del Jugador: " << jugadorUsuario->getEleccion() <<'\n';
    cout << "Eleccion de la Computadora: " << jugadorComputadora->getEleccion() <<'\n';

    if (jugadorUsuario->getEleccion() == jugadorComputadora->getEleccion()) {
        cout << "¡Empate!" <<'\n';
        jugadorUsuario->setPuntaje(jugadorUsuario->getPuntaje() + 1);
        jugadorComputadora->setPuntaje(jugadorComputadora->getPuntaje() + 1);
    }
    else if ((jugadorUsuario->getEleccion() == 1 && jugadorComputadora->getEleccion() == 2) ||
        (jugadorUsuario->getEleccion() == 2 && jugadorComputadora->getEleccion() == 3) ||
        (jugadorUsuario->getEleccion() == 3 && jugadorComputadora->getEleccion() == 1)) {
        cout << "¡Ganaste!" <<'\n';
        jugadorUsuario->setPuntaje(jugadorUsuario->getPuntaje() + 1);
    }
    else {
        cout << "Perdiste" <<'\n';
        jugadorComputadora->setPuntaje(jugadorComputadora->getPuntaje() + 1);
    }

    cout << "Puntaje del Jugador: " << jugadorUsuario->getPuntaje() <<'\n';
    cout << "Puntaje de la Computadora: " << jugadorComputadora->getPuntaje() <<'\n';

    delete jugadorUsuario;
    delete jugadorComputadora;

    return 0;
}
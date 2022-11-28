#ifndef TP_JUEGODEPALABRAS_JUEGO_H
#define TP_JUEGODEPALABRAS_JUEGO_H

#include "Variante.h"


class Juego {
public:
    const Nat numJugadores() const;
    Juego(Nat numJugadores, Variante var, Repositorio rep);
    void ubicar(Ocurrencia o);
    const Variante obtenerVariante() const;
    const Nat obtenerTurno() const;
    const Nat obtenerPuntaje(Nat j);
    const bool EsjugadaValida(Ocurrencia o);
    const Letra fichaEnPosicion(Nat fila , Nat columna) const;
    const bool hayFicha(Nat fila, Nat columna) const;
    const Nat cuantasDeEstaTiene(Letra l, Nat idCliente) const;
    const Nat tamanoTab() const;

private:
    Repositorio _rep;
    struct Casillero{
        Letra letra;
        Nat   turnoJugado;
        bool  ocupado;
    };
    using Tablero = vector<vector<Casillero>>;
    Tablero tablero;
    Variante v;
    Nat numJug;
    Nat turnoActual;
    struct jugador{
        using Mano = vector<int>;
        Mano mano;
        Nat puntaje;
        Ocurrencia fichasQuePusoDesde;

    };
    using Jugadores = vector<jugador>;
    Jugadores jugadores;
    Jugadores repartirFichas(Variante v, Nat cantJugadores, Repositorio rep);
    Tablero crearTablero(Nat tamano);
    void agregarPalabraHorizontal(ConjTrie conjPalabras, pair<Nat, Nat> prim, pair<Nat, Nat> ult);
    void agregarPalabraVertical(ConjTrie conjPalabras, pair<Nat, Nat> arr, pair<Nat, Nat> abj);
    Nat puntajeTotal(ConjTrie conjPalabras);
    const bool enRango(Nat i, Nat j);
    const bool Horizontal(Ocurrencia o) const;
    const bool Vertical(Ocurrencia o) const;
    const bool sonContiguas(pair<Nat, Nat> prim, pair<Nat, Nat> ult, bool horizontal);
};

#endif //TP_JUEGODEPALABRAS_JUEGO_H

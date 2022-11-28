#include "Fachada_Juego.h"

Fachada_Juego::Fachada_Juego(Nat k, const Fachada_Variante &v, const Repositorio &r): juego(k,v.daVariante(),r)
,fachaVar(v.tamanoTablero(), v.fichas(), v.obtPuntajes(), v.obtPalabrasLeg()){}

void Fachada_Juego::ubicar(const Ocurrencia &o) {
juego.ubicar(o);
}

IdCliente Fachada_Juego::turno() {
    return juego.obtenerTurno();
}

const Fachada_Variante &Fachada_Juego::variante() {
    return fachaVar;
}

bool Fachada_Juego::jugadaValida(const Ocurrencia &o) {
    return juego.EsjugadaValida(o);
}

bool Fachada_Juego::hayLetra(Nat x, Nat y) {
    return juego.hayFicha(x,y);
}

Letra Fachada_Juego::letra(Nat i, Nat j) {
    return juego.fichaEnPosicion(i,j);
}

Nat Fachada_Juego::puntaje(IdCliente id) {
    return juego.obtenerPuntaje(id);
}

Nat Fachada_Juego::cantFicha(IdCliente id, Letra l) {
    return juego.cuantasDeEstaTiene(l,id);
}

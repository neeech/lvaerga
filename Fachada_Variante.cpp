#include "Fachada_Variante.h"

Fachada_Variante::Fachada_Variante(Nat tamanoTab, Nat cantFichas, const map<Letra, Nat> &puntajes,
                                   const set<vector<Letra>> &palabrasLegitimas)
        : _var(tamanoTab,cantFichas, puntajes,palabrasLegitimas){
    _puntajes = puntajes;
    _palabras = palabrasLegitimas;
}

Nat Fachada_Variante::tamanoTablero() const {
    return _var.tamanoTablero();
}

Nat Fachada_Variante::fichas() const {
    return _var.cantFichas();
}

Nat Fachada_Variante::puntajeLetra(Letra l) const {
    return _var.puntajeLetra(l);
}

bool Fachada_Variante::palabraLegitima(const Palabra &palabra) const {
    return _var.palabraLegitima(palabra);
}

const map<Letra, Nat> Fachada_Variante::obtPuntajes() const {
    return _puntajes;
}

const set<vector<Letra>> Fachada_Variante::obtPalabrasLeg() const {
    return _palabras;
}

const Variante Fachada_Variante::daVariante() const {
    return _var;
}


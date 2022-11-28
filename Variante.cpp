#include "Variante.h"


Variante::Variante(Nat tamanoTab, Nat cantFichas, const map<Letra, Nat> &puntajes,
                   const set<vector<Letra>> &palabrasLegitimas){

    Abecedario abc(puntajes.size(),0);
    abecedario = abc;
    for(auto x: puntajes){
        abecedario[ord(x.first)] = x.second;
    }

    string s;

    for (auto pal: palabrasLegitimas) {

        universal.insert(pal);

    }
    lmax = universal.obtenerLmax();
}



Nat Variante::tamanoTablero() const {
    return tamanioTablero;
}

Nat Variante::cantFichas() const {
    return fichasCant;
}

Nat Variante::puntajeLetra(Letra l) const {
    return abecedario[ord(l)];
}

bool Variante::palabraLegitima(const Palabra &palabra) const {
    return universal.count(palabra);
}

const Nat Variante::obtenerLmax() const {
    return lmax;
}


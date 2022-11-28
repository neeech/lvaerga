#ifndef TP_JUEGODEPALABRAS_VARIANTE_H
#define TP_JUEGODEPALABRAS_VARIANTE_H

#include "Tipos.h"
#include "Letra.h"
#include "ConjTrie.h"

class Variante {
public:

    Variante(const Nat tamanoTab,
            Nat cantFichas,
            const map<Letra, Nat>& puntajes,
            const set<Palabra>& palabrasLegitimas
    );

    Nat tamanoTablero() const;
    Nat cantFichas() const;
    Nat puntajeLetra(Letra l) const;
    bool palabraLegitima(const Palabra& palabra) const;
    const Nat obtenerLmax() const;

private:
    Abecedario abecedario;
    ConjTrie universal;
    Nat fichasCant;
    Nat tamanioTablero;
    Nat lmax;
};

#endif //TP_JUEGODEPALABRAS_VARIANTE_H

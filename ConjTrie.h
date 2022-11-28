#ifndef CONJ_TRIE_H_
#define CONJ_TRIE_H_

#include "Tipos.h"
#include "Letra.h"

using namespace std;

class ConjTrie {
public:
    /**
    CONSTRUCTOR
    * Construye un diccionario vacio.
    **/
    ConjTrie();

    /**
    DESTRUCTOR
    **/
    ~ConjTrie();


    void insert(Palabra);

    /**
    COUNT
    * Devuelve la cantidad de apariciones de la clave (0 o 1).
    * Sirve para identificar si una clave está definida o no.
    **/

    int count(Palabra palabra) const;

    /**
     SIZE
     * Devuelve cantidad de claves definidas */
    int size() const;

    Nat obtenerLmax();

    set<Palabra> palabras();

private:

    struct Nodo {
        Nodo() : siguientes(TAMANIO_ALFABETO, nullptr),
                 definido(false) { };

        vector<Nodo*> siguientes;
        bool definido;

    };
    Nodo* raiz;
    int _size;
    Nat lmax;
    set<Palabra> _claves;

    void destruir(Nodo* n);
};


#endif // CONJ_TRIE_H_

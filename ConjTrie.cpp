#include "ConjTrie.h"

ConjTrie::ConjTrie(): raiz(nullptr), _size(0), _claves(), lmax(0){
    // COMPLETAR
}

ConjTrie::~ConjTrie(){
    // COMPLETAR
    if (raiz != nullptr){
        destruir(raiz);
    }
}

void ConjTrie::destruir(Nodo* n){

    for (Nodo* hijo: n->siguientes) {
        if(hijo != nullptr){
            destruir(hijo);
        }
    }
    delete n;

}

void ConjTrie::insert(Palabra palabra) {
    // COMPLETAR

    if(palabra.size() > lmax){
        lmax = palabra.size();
    }

    if(raiz== nullptr){
        raiz = new Nodo();
    }
    Nodo *actual = raiz;
    for (auto c: palabra) {
        if (actual->siguientes[ord(c)] == nullptr){
            actual->siguientes[ord(c)] = new Nodo();
        }
        actual = actual->siguientes[ord(c)];
    }
    if(actual->definido == false){
        (actual->definido) = true;
        _size++;
    }

    _claves.insert(palabra);
}

int ConjTrie::count(Palabra palabra) const{
    // COMPLETAR
    if (raiz == nullptr){
        return 0;
    }
    Nodo* actual = raiz;
    for (auto c: palabra) {
        if (actual->siguientes[ord(c)] == nullptr){
            return 0;
        }
        actual = actual->siguientes[ord(c)];
    }
    if (actual->definido == false){
        return 0;
    }
    return 1;

}



int ConjTrie::size() const{
    // COMPLETAR
    return _size;
}

Nat ConjTrie::obtenerLmax() {
    return lmax;
}

set<Palabra> ConjTrie::palabras() {
    return _claves;
}
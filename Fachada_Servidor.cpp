#include "Fachada_Servidor.h"

Fachada_Servidor::Fachada_Servidor(Nat cantJugadores, const Fachada_Variante &variante, const Repositorio &r) {

}

IdCliente Fachada_Servidor::conectarCliente() {
    return 0;
}

void Fachada_Servidor::recibirMensaje(IdCliente id, const Ocurrencia &o) {

}

Nat Fachada_Servidor::jugadoresEsperados() {
    return 0;
}

Nat Fachada_Servidor::jugadoresConectados() {
    return 0;
}

std::list<Notificacion> Fachada_Servidor::notificaciones(IdCliente id) {
    return std::list<Notificacion>();
}

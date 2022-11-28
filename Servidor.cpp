#include "Servidor.h"

Servidor::Servidor(Nat cantJug, Variante v, Repositorio rep): juego(cantJug,v,rep){
    _clientes.esperados = cantJug;
    _clientes.conectados = 0;
    vector<tuple<Notificacion,Nat>> vacio = {};
    vector<vector<tuple<Notificacion,Nat>>> porJugador(cantJug, vacio) ;
    _notifs.notificacionesPorJugador = porJugador;
    _notifs.nTodes.notificacionesServidor = {};
    vector<int> leyoHasta(cantJug,0);
    _notifs.nTodes.leyoHasta = leyoHasta;
    _idNotif = 0;

}

void Servidor::conectarCliente() { //TODO : mandar fichas como en el mail


    _notifs.notificacionesPorJugador[_clientes.conectados].push_back(make_tuple(Notificacion ::nuevaIdCliente(_clientes.conectados),_idNotif));
    _idNotif++;
    if (_clientes.conectados == _clientes.esperados){
        _notifs.nTodes.notificacionesServidor.push_back(make_tuple(Notificacion ::nuevaEmpezar(juego.tamanoTab()),_idNotif));
        _notifs.nTodes.notificacionesServidor.push_back(make_tuple(Notificacion::nuevaTurnoDe(0), ++ _idNotif));
        _idNotif++;
    }
    _clientes.conectados ++;


}

void Servidor::recibirMensaje(Ocurrencia o, Nat idCliente) {

}

const Nat Servidor::numeroClientesEsperados() const {
    return 0;
}

const Nat Servidor::numeroClientesConectados() const {
    return 0;
}

void Servidor::consultarNotificaciones(Nat idCliente) {

}

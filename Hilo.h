#ifndef HILO_H
#define HILO_H

#include "Mensaje.h"
#include <vector>

using namespace std;

class Hilo {
    vector<Mensaje> *mensajes;
    string titulo;
    
    public:
        Hilo (string titulo) : titulo(titulo) {mensajes = new vector<Mensaje>;}
        string getTitulo() {return this->titulo;}
        vector<Mensaje>* getMensajes() {return mensajes;}
        Mensaje* nuevoMensaje(string contenido, Usuario *usuario);
        int numMensajes(){return this->mensajes->size();}
        Mensaje* verMensaje(int numeroMensaje){return &(mensajes->at(numeroMensaje));}
        vector<Mensaje>* buscarMensajes(string termino);
        ~Hilo(){}
};

#endif


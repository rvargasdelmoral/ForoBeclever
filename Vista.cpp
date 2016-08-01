#include "Vista.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

Vista::Vista() {
    foro = new Foro("Beclever");
    mensajeInicial();
}

void Vista::mensajeInicial() {
    int resultado;    
    while (true) {       
        cout << "\nELIGE UNA OPCION" << endl
        << "====================================================" << endl
        << "\n1: Registrarme en el foro" <<endl
        << "2: Identificarme" << endl
        << "3: Acceder como invitado " << endl;
        cin >> resultado;       
        switch (resultado) {
            case 1:
                registro();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "Elegido 3" << endl;
                exit(0);
                break;
            default:
                continue;       
        }
        break;
    }
}

void Vista::registro() {
    string nombreUsuario;
    string alias;
    string pass;
    string pass2;
    
    cout << "\nRegistro:" << endl
    << "====================================================" << endl
    << "\nIntroduce un nombre de usuario:" << endl;
    cin >> nombreUsuario;
    cout << "Introduce un alias:" << endl;
    cin >> alias;
    
    while (true) {
        cout << "Introduce una clave" << endl;
        cin >> pass;
        cout << "Vuelve a introducir la clave" << endl;
        cin >> pass2;
        if (pass.compare(pass2) == 0)
            break;
        else {
            cout << endl << "=== Las claves no coinciden ===" << endl << endl;
            continue;          
        }             
    }
    foro->nuevoUsuario(nombreUsuario, alias, pass);   
    mensajeInicial();
}

void Vista::login() {	
        cout << "\nLogin (\"exit\" para salir)" << endl
        << "====================================================\n" << endl;    
	string usuario;
	string pass;
        bool login = false;
        do {        
            cout << "Usuario:" << endl;
            cin >> usuario;
            
            if (usuario.compare("exit") == 0 or pass.compare("exit") == 0)
                mensajeInicial();
            
            cout << "Clave:" << endl;
            cin >> pass;      
            
            if (usuario.compare("exit") == 0 or pass.compare("exit") == 0)
                mensajeInicial();

            for (int i = 0; i < foro->getUsuarios()->size(); i++ ) {
                if ((foro->getUsuarios()->at(i).getNombre().compare(usuario) == 0) && (foro->getUsuarios()->at(i).getPass().compare(pass) == 0)){
                    login = true;
                    vistaForo(&(foro->getUsuarios()->at(i)));
                }    
            }
            if (!login)
                cout << "\nLogin incorrecto\n" << endl;
        }
        while (!login);     
        
}

void Vista::vistaForo(Usuario *u) {
    int resultado;
    cout << "\nBIENVENIDO " << u->getNombre() << " al Foro: \"" << foro->getNombre() << "\"" << endl
    << "====================================================\n" << endl;

    while (true) {       
        cout << "1: Crear Tema" <<endl
        << "2: Ver temas" << endl
        << "3: Configuracion de usuario " << endl
        << "4: Cerrar sesion y salir al menu principal" << endl;        
        cin >> resultado;       
        switch (resultado) {
            case 1:
                crearTema(u);
                break;
            case 2:
                verTemas(u);
                break;
            case 3:
                cout << "Elegido 3" << endl;
                break;
            case 4:
                mensajeInicial();
            default:
                continue;       
        }
    break;
    }
}

void Vista::crearTema(Usuario *u) {
    string titulo;
    cout << "\nIntroduce el titulo del tema" << endl;
    cin.ignore();
    getline(cin, titulo);
    foro->nuevoTema(titulo);
    cout << "Nuevo tema: " << "\"" << titulo << "\"" << " creado correctamente" << endl;
    vistaForo(u);
    
}

void Vista::verTemas(Usuario* u) {
    int numeroTema;
    Tema *t;
    cout << "\nTemas" << endl
    << "====================================================\n" << endl; 
    
    for (int i = 0; i < foro->numTemas(); i++) {
        cout << i+1 << "-> " << foro->verTema(i)->getDenominacion() << endl;
    }
    
    do {
        cout << "Introduce el numero de tema para acceder a el" << endl
        << "0 para volver al menu principal" << endl;
        cin >> numeroTema;
    }
    while(!(numeroTema >= 0 && numeroTema <= foro->numTemas()));
    
    if (numeroTema == 0)
        vistaForo(u);
    else {
        t = foro->verTema(numeroTema);
        menuTema(u, t);
    }
    
}

void Vista::menuTema(Usuario*u, Tema *t) {
    int resultado;
    
    cout << "\nBIENVENIDO " << u->getNombre() << " al Tema: \"" << t->getDenominacion() << "\"" << endl
    << "====================================================\n" << endl;
    
    while (true) {       
        cout << "1: Nuevo hilo" <<endl
        << "2: Ver hilos" << endl
        << "3: Buscar hilo por nombre " << endl
        << "4: Volver al menu de temas" << endl;        
        cin >> resultado;       
        switch (resultado) {
            case 1:
                crearHilo(u, t);
                break;
            case 2:
                verHilos(u, t);
                break;
            case 3:
                cout << "Elegido 3" << endl;
                break;
            case 4:
                verTemas(u);
            default:
                continue;      
        }
    break;
    }
}

void Vista::crearHilo(Usuario* u, Tema *t) {
    string titulo;
    string mensajeInicial;
    
    cout << "\nIntroduce un titulo" << endl;
    cin.ignore();
    getline(cin, titulo);
    
    cout << "\nIntroduce un mensaje inicial" << endl;
    cin.ignore();
    getline(cin, mensajeInicial);
    
    t->nuevoHilo(titulo, new Mensaje(mensajeInicial, u));   
}

void Vista::verHilos(Usuario* u, Tema* t) {
    
}












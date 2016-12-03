#include <string>
#include <sstream>
#include "Administrador.h"

using std::stringstream;
using std::string;

Administrador::Administrador(): Usuario(){
    
}


Administrador::Administrador(string user,string email,string password, string fecha) : Usuario(user,email,password),fecha(fecha){
    
}

void Administrador::setFecha(string pFecha){
  fecha = pFecha;
}

string Administrador::getFecha(){
  return fecha;
}

string Administrador::toString(){
	stringstream ss;
	ss<<user<<" "<<email<<" "<<password<<" "<<fecha<<" ";
	return ss.str();
}
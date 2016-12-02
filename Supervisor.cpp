#include <string>
#include <sstream>
#include "Supervisor.h"

using std::stringstream;
using std::string;

Supervisor::Supervisor(): Usuario(){
    
}


Supervisor::Supervisor(string user,string email,string password, int contador) : Usuario(user,email,password),contador(contador){
    
}

void Supervisor::setContador(string pContador){
  contador = pContador;
}

int Supervisor::getContador(){
  return contador;
}

string Supervisor::toString(){
	stringstream ss;
	ss<<contador;
	return ss.str();
}
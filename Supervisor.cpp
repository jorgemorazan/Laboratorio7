#include <string>
#include <sstream>
#include "Supervisor.h"

using std::stringstream;
using std::string;

Supervisor::Supervisor(): Usuario(){
    
}


Supervisor::Supervisor(string user,string email,string password, int contador) : Usuario(user,email,password),contador(contador){
    
}

void Supervisor::setContador(int pContador){
  contador = pContador;
}

int Supervisor::getContador(){
  return contador;
}

string Supervisor::toString(){
	stringstream ss;
	ss<<user<<" "<<email<<" "<<password<<" "<<contador;
	return ss.str();
}
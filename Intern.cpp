#include <string>
#include <sstream>
#include "Intern.h"

using std::stringstream;
using std::string;

Intern::Intern(): Usuario(){
    
}


Intern::Intern(string user,string email,string password, string dias) : Usuario(user,email,password),dias(dias){
    
}

void Intern::setDias(string pDias){
  dias = pDias;
}

string Intern::getDias(){
  return dias;
}

string Intern::toString(){
	stringstream ss;
	ss<<dias;
	return ss.str();
}
#include <string>
#include <sstream>
#include "Manager.h"

using std::stringstream;
using std::string;

Manager::Manager(): Usuario(){
    
}


Manager::Manager(string user,string email,string password, string sueldo) : Usuario(user,email,password),sueldo(sueldo){
    
}

void Manager::setSueldo(string pSueldo){
  sueldo = pSueldo;
}

string Manager::getSueldo(){
  return sueldo;
}

string Manager::toString(){
	stringstream ss;
	ss<<sueldo;
	return ss.str();
}
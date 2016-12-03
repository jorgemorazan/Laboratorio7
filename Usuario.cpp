#include <string>
#include <sstream>
using std::stringstream;
using std::string;
#include "Usuario.h"

Usuario::Usuario(){

}

Usuario::~Usuario() {

}

Usuario::Usuario(string user, string email,string password){
	this->user = user;
	this->email = email;
	this->password = password;
}

void Usuario::setUser(string pUser){
  user = pUser;
}

string Usuario::getUser(){
  return user;
}

void Usuario::setEmail(string pEmail){
  email = pEmail;
}

string Usuario::getEmail(){
  return email;
}

void Usuario::setPassword(string pPassword){
  password = pPassword;
}

string Usuario::getPassword(){
  return password;
}

string Usuario::toString(){
	stringstream ss;
	ss<<"Usuario: "<<user<<" Email: "<<email<<" Password: "<<password;
	return ss.str();
}
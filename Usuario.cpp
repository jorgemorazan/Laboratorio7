#ifndef USUARIO_H
#define USUARIO_H 
#include <string>

using std::string;

class Usuario{
private:
	string user;
	string email;
	string password;
	int nivel;
public:
	Usuario(string,string,string);
	Usuario();
	virtual ~Usuario();
	void setUser(string);
	string getUser();
	void setEmail(string);
	string getEmail();
	void setPassword();
	string getPassword();
	string toString();
};
#endif
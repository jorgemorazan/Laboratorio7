#ifndef SUPERVISOR_H
#define SUPERVISOR_H
#include <string>
#include "Usuario.h"

using std::string;

class Supervisor : public Usuario {
    private:
    	int contador;
    public:
        Supervisor(string,string,string,int);
        Supervisor();
        void setContador(int);
		int getContador();
		string toString();
};

#endif
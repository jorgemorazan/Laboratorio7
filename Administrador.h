#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <string>
#include "Usuario.h"

using std::string;

class Administrador : public Usuario {
    private:
    	string fecha;
    public:
        Administrador(string,string,string,string);
        Administrador();
        void setFecha(string);
		string getFecha();
		string toString();
};

#endif
#ifndef MANAGER_H
#define  MANAGER_H
#include <string>
#include "Usuario.h"

using std::string;

class Manager : public Usuario {
    private:
    	string sueldo;
    public:
        Manager(string,string,string,string);
        Manager();
        void setSueldo(string);
		string getSueldo();
		string toString();
};

#endif
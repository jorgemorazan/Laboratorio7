#ifndef INTERN_H
#define INTERN_H
#include <string>
#include "Usuario.h"

using std::string;

class Intern : public Usuario {
    private:
    	string dias;
    public:
        Intern(string,string,string,string);
        Intern();
        void setDias(string);
		string getDias();
		string toString();
};

#endif
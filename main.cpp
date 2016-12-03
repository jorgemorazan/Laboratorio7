#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Usuario.h"
#include "Administrador.h"
#include "Manager.h"
#include "Intern.h"
#include "Supervisor.h"
#include <fstream>
#include <stdlib.h>

using namespace std;
int main(){
	bool esAdmin=false, esManager=false, esIntern=false, esSupervisor=false;
	vector<Administrador*>admin;
	vector<Manager*>managers;
	vector<Intern*>interns;
	vector<Supervisor*>supervisores;
	string nombre, correo, contra, otro;
	ifstream mana;
	ifstream inter;
	ifstream super;
	mana.open("Managers.txt");
	if(mana.fail()){
		cout<<"ERROR";
	}else{
		while(!mana.eof()){
			getline(mana, nombre, ' ');
			getline(mana, correo, ' ');
			getline(mana, contra, ' ');
			getline(mana, otro, ' ');
			managers.push_back(new Manager(nombre, correo, contra, otro));
		}
		mana.close();
	}
	inter.open("Interns.txt");
	if(inter.fail()){
		cout<<"ERROR";
	}else{
		while(!inter.eof()){
			getline(inter, nombre, ' ');
			getline(inter, correo, ' ');
			getline(inter, contra, ' ');
			getline(inter, otro, ' ');
			interns.push_back(new Intern(nombre, correo, contra, otro));
		}
		inter.close();
	}
	super.open("Supervisores.txt");
	if(super.fail()){
		cout<<"ERROR";
	}else{
		while(!super.eof()){
			getline(super, nombre, ' ');
			getline(super, correo, ' ');
			getline(super, contra, ' ');
			getline(super, otro, ' ');
			supervisores.push_back(new Intern(nombre, correo, contra, atoi(otro.c_str()));
		}
		super.close();
	}
	//string user,string email,string password, string fecha
	admin.push_back(new Administrador("admin","admin@admin.com","admin001","03/09/1964"));
	string username, password;
	cout<<"Ingrese su Username: ";
	cin>>username;
	cout<<"Ingrese su password: ";
	cin>>password;
	if(admin.at(0)->getUser()==username && admin.at(0)->getPassword()==password){
		esAdmin=true;
	}
	for (int i = 0; i < managers.size(); ++i)
	{
		if(managers.at(i)->getUser()==username && managers.at(i)->getPassword()==password){
			esManager=true;
		}
	}
	for (int i = 0; i < interns.size(); ++i)
	{
		if(interns.at(i)->getUser()==username && interns.at(i)->getPassword()==password){
			esIntern=true;
		}
	}
	for (int i = 0; i < supervisores.size(); ++i)
	{
		if(supervisores.at(i)->getUser()==username && supervisores.at(i)->getPassword()==password){
			esSupervisor=true;
			int cont=0;
			cont = supervisores.at(i)->getContador();
			cont+=1;
			supervisores.at(i)->setContador(cont);
		}
	}
	if(esAdmin||esManager){
		string ingresado;
		if(esAdmin){
			ingresado="Administrador";
		}else{
			ingresado="Manager";
		}
		int opc=0;
		do{
			cout<<ingresado<<endl<<"1. Crear Usuario\n2. Eliminar Usuario\n3. Salir\n";
			cin>>opc;
			if(opc==1){
				int opcion=0;
				if(esAdmin){
					do{
						cout<<"1. Manager\n2. Intern\n3. Supervisor\n";
						cin>>opcion;
					}while(opcion<1 && opcion>3);
				} else {
					do{
						cout<<"1. Intern\n2. Supervisor\n";
						cin>>opcion;
					}while(opcion<1 && opcion>2);
					opcion++;
				}
				string user, email, pass;
				int sz=0;
				cout<<"Ingrese el nombre del usuario: ";
				cin>>user;
				cout<<"Ingrese el email del usuario: ";
				cin>>email;
				if(opcion==1){//Manager
					//(string user,string email,string password, string sueldo)
					do{
						cout<<"Ingrese el password del usuario: ";
						cin>>pass;
						sz=pass.size();
						if(sz!=16){
							cout<<endl<<"Tiene que tener 16 caracteres la contraseña"<<endl;
						}
					}while(sz!=16);
					string sueldo;
					cout<<"Ingrese el sueldo del Manager: ";
					cin>>sueldo;
					managers.push_back(new Manager(user, email, pass, sueldo));
				}
				if(opcion==2){
					//(string user,string email,string password, string dias)
					do{
						cout<<"Ingrese el password del usuario: ";
						cin>>pass;
						sz=pass.size();
						if(sz!=8){
							cout<<endl<<"Tiene que tener 8 caracteres la contraseña"<<endl;
						}
					}while(sz!=8);
					string dias;
					cout<<"Ingrese los días del Interno: ";
					cin>>dias;
					interns.push_back(new Intern(user, email, pass, dias));
				}
				if(opcion==3){
					do{
						cout<<"Ingrese el password del usuario: ";
						cin>>pass;
						sz=pass.size();
						if(sz!=8){
							cout<<endl<<"Tiene que tener 8 caracteres la contraseña"<<endl;
						}
					}while(sz!=8);
					supervisores.push_back(new Supervisor(user, email, pass, 0));
				}
				//vector.erase(vector.begin()+numeropedido);
			}//fin opcion 1
			if(opc==2){
				int opcion=0;
				if(esAdmin){
					do{
						cout<<"1. Manager\n2. Intern\n3. Supervisor\n";
						cin>>opcion;
					}while(opcion<1 && opcion>3);
				} else {
					do{
						cout<<"1. Intern\n2. Supervisor\n";
						cin>>opcion;
					}while(opcion<1 && opcion>2);
					opcion++;
				}
				if(opcion==1){
					int eraseMe;
					for (int i = 0; i < managers.size(); ++i)
					{
						cout<<i<<"-"<<managers.at(i)->toString()<<endl;
					}
					cout<<"Elija cual quiere eliminar: ";
					cin>>eraseMe;
					managers.erase(managers.begin()+eraseMe);
				}
				if(opcion==2){
					int eraseMe;
					for (int i = 0; i < interns.size(); ++i)
					{
						cout<<i<<"-"<<interns.at(i)->toString()<<endl;
					}
					cout<<"Elija cual quiere eliminar: ";
					cin>>eraseMe;
					interns.erase(interns.begin()+eraseMe);
				}
				if(opcion==3){
					int eraseMe;
					for (int i = 0; i < supervisores.size(); ++i)
					{
						cout<<i<<"-"<<supervisores.at(i)->toString()<<endl;
					}
					cout<<"Elija cual quiere eliminar: ";
					cin>>eraseMe;
					supervisores.erase(supervisores.begin()+eraseMe);
				}
			}//fin eliminar

		}while(opc!=3);
	}

	if(esIntern){
		int opt=0;
		do{
			cout<<endl"Intern"<<endl<<"1. Ver usuarios\n2. Eliminar Usuario\n3. Salir";
			if(opt==1){
				for (int i = 0; i < interns.size(); ++i)
				{
					cout<<i<<"-"<<interns.at(i)->toString()<<endl;
				}
			}
			if(opt==2){
				int eraseMe;
				for (int i = 0; i < interns.size(); ++i)
				{
					cout<<i<<"-"<<interns.at(i)->toString()<<endl;
				}
				cout<<"Elija cual quiere eliminar: ";
				cin>>eraseMe;
				interns.erase(interns.begin()+eraseMe);
			}
		}while(opt!=3);
		//vector.erase(vector.begin()+numeropedido);
	}
	if(esSupervisor){
		cout<<endl"MANAGERS"<<endl;
		for (int i = 0; i < managers.size(); ++i)
		{
			cout<<i<<"-"<<managers.at(i)->toString()<<endl;
		}
		cout<<"INTERNS"<<endl;
		for (int i = 0; i < interns.size(); ++i)
		{
			cout<<i<<"-"<<interns.at(i)->toString()<<endl;
		}
		cout<<"SUPERVISORES"<<endl;
		for (int i = 0; i < supervisores.size(); ++i)
		{
			cout<<i<<"-"<<supervisores.at(i)->toString()<<endl;
		}
	}
	ofstream file;
	file.open("Managers.txt");
	
	for (int i = 0; i < managers.size(); ++i)
	{
		if(managers.at(i)!=NULL){
			file<< i<<"-"<<managers.at(i)->toString()<<endl;
		}
	}
	ofstream file;
	file.open("Interns.txt");
	
	for (int i = 0; i < managers.size(); ++i)
	{
		if(managers.at(i)!=NULL){
			file<< i<<"-"<<managers.at(i)->toString()<<endl;
		}
	}
	ofstream file;
	file.open("Supervisores.txt");
	
	for (int i = 0; i < managers.size(); ++i)
	{
		if(managers.at(i)!=NULL){
			file<< i<<"-"<<managers.at(i)->toString()<<endl;
		}
	}
	return 0;
}
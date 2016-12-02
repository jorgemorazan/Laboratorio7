#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
	bool esAdmin=false, esManager=false, esIntern=false, esSupervisor=false;
	vector<Administrador*>admin;
	vector<Manager*>managers;
	vector<Intern*>interns;
	vector<Supervisor*>supervisores;
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
					}while(sz>16);
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
					}while(sz>8);
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
					}while(sz>8);
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
					managers.erase(vector.begin()+eraseMe);
				}
				if(opcion==2){
					int eraseMe;
					for (int i = 0; i < interns.size(); ++i)
					{
						cout<<i<<"-"<<interns.at(i)->toString()<<endl;
					}
					cout<<"Elija cual quiere eliminar: ";
					cin>>eraseMe;
					interns.erase(vector.begin()+eraseMe);
				}
				if(opcion==3){
					int eraseMe;
					for (int i = 0; i < supervisores.size(); ++i)
					{
						cout<<i<<"-"<<supervisores.at(i)->toString()<<endl;
					}
					cout<<"Elija cual quiere eliminar: ";
					cin>>eraseMe;
					supervisores.erase(vector.begin()+eraseMe);
				}
			}//fin eliminar

		}while(opc!=3);
	}

	if(esIntern){
		//vector.erase(vector.begin()+numeropedido);
	}
	if(esSupervisor){

	}
	return 0;
}
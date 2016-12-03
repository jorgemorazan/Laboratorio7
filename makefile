main:	main.o Usuario.o Intern.o Manager.o Supervisor.o Administrador.o
	g++ main.o Usuario.o Intern.o Manager.o Supervisor.o Administrador.o -o main

main.o:	main.cpp Usuario.h Intern.h Manager.h Supervisor.h Administrador.h
	g++ -c main.cpp

Usuario.o:	Usuario.h Usuario.cpp
	g++ -c Usuario.cpp

Intern.o:	Usuario.h Intern.cpp Intern.h
	g++ -c Intern.cpp

Manager.o:	Usuario.h Manager.cpp Manager.h
	g++ -c Manager.cpp

Supervisor.o:	Usuario.h Supervisor.cpp Supervisor.h
	g++ -c Supervisor.cpp	

Administrador.o:	Usuario.h Administrador.cpp Administrador.h
	g++ -c Administrador.cpp
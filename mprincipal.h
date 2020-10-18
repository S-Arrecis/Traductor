#include <iostream>
#include <conio.h>
using namespace std;

class principal
{
public:	
	void menu();
	void Traductor();
	void Editar();	
};

	void stop()
	{
    	cout<<"Presione enter para continuar...";
    	getch();
    	system("cls");
	}
	
	void error()
	{
		cout<<"Opcion incorrecta, presione enter para continuar...";
    	getch();
    	system("cls");
	}
	
	void principal::menu()
	{
    	int seleccion;
    	do
    	{
        	cout<<"--------------------Proyecto Traductor--------------------"<<endl;
        	cout<<"Bienvenido al traductor, en el siguiente listado encontrara las opciones a escoger, \n ingrese en la parte inferior el numero de la opcion \n"<<endl;
        	cout<<"1. Utilizar traductor"<<endl;
        	cout<<"2. Editar"<<endl;
        	cout<<"3. Salir \n"<<endl;
        	cout<<"Seleccione opcion: \n";
        	cin>>seleccion;
        	system("cls");
        	switch(seleccion)
        	{
            	break;
        		case 1:
            		Traductor();
            	break;
        		case 2:
            		Editar();
            	break;
        		case 3:
            	break;
            		default:
            			error();
        	}
    	}	
    while(seleccion!=3);
	}


	void principal::Traductor() //funcion que llama al traductor
	{
		{
    	}
    stop();
	}
	
	void principal::Editar() //funcion que llama al editor
	{
		{
    	}
    stop();
	}
	
	int main()
	{
    	principal inicio;
    	inicio.menu();
    	return 0;
}

#include<locale.h>
#include<iostream>
#include<fstream>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include "Agregar.h"

using namespace std;

void menuinit();
void error();
void stop();
void Traductor();
void Editar();

int main(){
	
	setlocale(LC_CTYPE, "Spanish");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	
	menuinit();

	system("pause");
	return 0;
}

void error()
	{
		//system("pause");
		cout<<"Opci�n incorrecta, presione enter para continuar...";
    	getch();
    	system("cls");
	}

	void stop()
	{
    	system("pause");

    	system("cls");
	}

	void Traductor(){
		cout<<"TRADUCTOR"<<endl;
		traducir();

	}

	void Editar(){
		system("agregar.exe");
	}

void menuinit(){
    	int seleccion;
    	do
    	{
        	cout<<"--------------------Proyecto Traductor--------------------"<<endl;
        	cout<<"Bienvenido al traductor, en el siguiente listado encontrara las opciones a escoger, \ningrese en la parte inferior el numero de la opci�n: \n"<<endl;
        	cout<<"1. Utilizar traductor"<<endl;
        	cout<<"2. Editar registros"<<endl;
        	cout<<"3. Salir \n"<<endl;
        	cout<<"Seleccione opci�n: \n";
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
            		system("agregar.exe");
            	break;
        		case 3:
            	break;
            		default:
            			error();
        	}
    	}	
    while(seleccion!=3);
	}


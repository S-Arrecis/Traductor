
#include<locale.h>
#include<iostream>
#include<fstream>
#include <windows.h>
//#include "Agregar.h"
#include<stdio.h>
#include<conio.h>

using namespace std;

void menuinit();
void error();
void stop();
void Traductor();
void Editar();
void proceso();
void motstrar_traduccion();


bool iniciado = true;


int menu(){
	int x;
	cout<<"-----------Menú Editar Registros------------"<<endl;
	cout<<"1. Agregar registro"<<endl;
	cout<<"2. Ver registros"<<endl;
	cout<<"3. Buscar registro"<<endl;
	cout<<"4. Editar registro"<<endl;
	cout<<"5. Eliminar registro"<<endl;
	cout<<"6. Regresar al menú principal"<<endl;

	cout<< "Opci�n: ";
	cin>>x;
	return x;
}

void agregar(ofstream &es) {
system("cls");	
	string Pal;
	string Tra;
	string Def;	
	es.open("PAlabras.txt",ios::out|ios::app);

	cout<<"Ingrese palabra en reservada"<<endl;
	cin>>Pal;
		fflush(stdin);
	cout<<"Ingrese traducci�n"<<endl;
	getline(cin,Tra);

		fflush(stdin);
	cout<<"Ingrese la definici�n"<<endl;
	getline(cin,Def);
	
	//agregarIngles(Pal);
	//agregarTraduccion(Tra);
	

	
	es<<Pal<<endl;
	es<<Tra<<endl;
	es<<Def<<endl;
	es.close();
	 cout<< "****Los registros han sido a�adidos exitosamente*****"<<endl;
	
	system("pause");
}

void ver(ifstream &Lec){
system("cls");
	string pal;
	string tra,tralong;
	string def,deflong;
	Lec.open("PAlabras.txt",ios::in);
	if(Lec.is_open()){
		Lec>>pal;
		while (!Lec.eof()){
			Lec>>tra;
		
			cout<<"Palabra en ingles: "<<pal<<endl;
				cout<<"Palabra en espaï¿½ol: "<<tra;
				getline(Lec,tralong);
					cout<<tralong<<endl;
						Lec>>def;
					cout<<"Definiciï¿½n: "<<def;
					getline(Lec,deflong);
					cout<<deflong<<endl;
					cout<<"---------------------------------------------------"<<endl;
			Lec>>pal;
			
		}
		Lec.close();
			}else
			cout<<"Error, no se pudo abrir el archivo, es probable que el archivo no exista"<<endl; 
	system("pause");
	;
		
}

void  bus(ifstream &Lec){
	system("cls");
	Lec.open("PAlabras.txt",ios::in);
	string pal,tra,def,id,tralong,deflong;
	
	bool encontrado = false;
	
	cout<<"Ingrese la palabra que desea buscar"<<endl;
	cin>>id;
	Lec>>pal;
	
	while(pal != id && !Lec.eof()){
		Lec>>pal;
		
	}
	
	
		while(!Lec.eof()){
		Lec>>tra;

		if(pal == id){
cout<<"---------------------------------------------------------------: "<<endl;
cout<<"La palabra reserbada que ingresó contiene los siguientes datos: "<<endl;
cout<<endl;
		cout<<"Palabra en ingles: "<<pal<<endl;
				cout<<"Palabra en espaï¿½ol: "<<tra;
				getline(Lec,tralong);
					cout<<tralong<<endl;
						Lec>>def;
					cout<<"Definiciï¿½n: "<<def;
					getline(Lec,deflong);
					cout<<deflong<<endl;
					cout<<"---------------------------------------------------"<<endl;
						encontrado = true;
		}				
			Lec>>pal;
	}
	Lec.close();
	if (!encontrado)
	cout<<"Dato no encontrado"<<endl;
	system("pause");
} 

void edit(ifstream & Lec){
	system("cls");
		
		cout<<"**********Editar Registros**********"<<endl;
		cout<<endl;
	string pal;
	string tra,tralong;
	string def,deflong;
	string id;
	string pal2,tra2,def2,deflong2;
	int opc;
	Lec.open("PAlabras.txt",ios::in );
	ofstream temp("temp.txt",ios::out);
	
	if(Lec.is_open()){
		cout<<"Digite la palabra reservada del registro que desea editar"<<endl;
		cin>>id;
		Lec>>pal;
				while(pal != id && !Lec.eof()){


			Lec>>tra;
				getline(Lec,tralong);
			Lec>>def;
				getline(Lec,deflong);

				if(pal != id){

				temp<<pal<<endl;
				temp<<tra;
				temp<<tralong<<endl;
				temp<<def;
				temp<<deflong<<endl;

						}
					Lec>>pal;

					if(Lec.eof()){
							cout<<"No se encontro palabra reservada en el  registro especificado"<<endl;
							temp.close();
								remove("temp.txt");
							system("pause");
							int main();
								main();
					}	
				}


		while(!Lec.eof()){	
			if(pal == id){
			Lec>>tra;
			cout<<"---------------------------------------------------------------: "<<endl;
			cout<<"La palabra reserbada que ingresó contiene los siguientes datos: "<<endl;
			cout<<endl;
			cout<<"Palabra en ingles: "<<pal<<endl;
				cout<<"Palabra en espaï¿½ol: "<<tra;
				getline(Lec,tralong);
					cout<<tralong<<endl;
						Lec>>def;
					cout<<"Definiciï¿½n: "<<def;
					getline(Lec,deflong);
					cout<<deflong<<endl;
					cout<<"---------------------------------------------------"<<endl;
		
					cout<<"INSTRUCCIONES: Ingrese los nuevos registros que se solicitan a continuacion, "<<endl;
				cout<<"si no desea editar alguno, debe ingresarlo igual nuevamente cuando se le solicite"<<endl;
				
				cout<<"Digite la nueva palabra reservada "<<endl;
				cin>>pal2;
			
						fflush(stdin);
					cout<<"Digite la nueva traducci�n: "<<endl;
					getline(cin,tra2);

						fflush(stdin);
					cout<<"Digite la nueva definici�n: "<<endl;
					getline(cin,def2);
	
	
						temp<<pal2<<endl;
						temp<<tra2<<endl;
						temp<<def2<<endl;
						
			 cout<<endl;
			 	system("cls");
			 cout<<"****************Confirmar Selecci�n*******************"<<endl;
			 cout<<endl;
			 cout<<"se editar�n todos los registros correspondientes a esta palabra reservada "<<endl;
			 cout<<endl;
			 
				cout<<"1. De acuerdo"<<endl;
				cout<<"2. No editar registros"<<endl;	
				cout<<"Opci�n: ";
				cin>>opc;
				cout<<endl;
	
				if (opc!=1){
					cout<<"No se edito ning�n registro"<<endl;
						temp.close();
						remove("temp.txt");
						system("pause");
						int main();
						main();
				}			
			} 
	Lec>>pal;
			 	if(!Lec.eof()){ 
					//temp<<pal<<" "<<tra<<" "<<def<<" "<<deflong<<endl;	
				temp<<pal<<endl;
				Lec>>tra;
						temp<<tra;
				getline(Lec,tralong);
						temp<<tralong<<endl;
				Lec>>def;
						temp<<def;
				getline(Lec,deflong);
						temp<<deflong<<endl;


						}
				
		}
		Lec.close();
		temp.close();
		
	}else{
	cout<<"Error no se pudo encontrar el archivo."<<endl;
}
	
	remove("PAlabras.txt");
	rename("temp.txt","PAlabras.txt");	
cout<<"*********El registro se ha modificado exitosamente**********"<<endl;	

			system("pause");	
	
}

void elim(ifstream &Lec){
	
	system("cls");
		
		cout<<"**********Eliminar Registros**********"<<endl;
		cout<<endl;
	string pal;
	string tra,tralong;
	string def,deflong;
	string id;
	string pal2,tra2,def2;
	int opc;
	Lec.open("PAlabras.txt",ios::in );
	ofstream temp("temp.txt",ios::out);
	
	if(Lec.is_open()){
		cout<<"Digite la palabra reservada del registro que desea eliminar"<<endl;
		cin>>id;
		Lec>>pal;
				while(pal != id && !Lec.eof()){
				Lec>>tra;
				getline(Lec,tralong);
			Lec>>def;
				getline(Lec,deflong);

				if(pal != id){

				temp<<pal<<endl;
				temp<<tra;
				temp<<tralong<<endl;
				temp<<def;
				temp<<deflong<<endl;
						}
					Lec>>pal;




					if(Lec.eof()){
							cout<<"No se encontro palabra reservada en el registro especificado"<<endl;
								temp.close();
								remove("temp.txt");
							system("pause");
							int main();
								main();
					}	
				}
		while(!Lec.eof()){	
			if(pal == id){
			Lec>>tra;
			cout<<"---------------------------------------------------------------: "<<endl;
			cout<<"La palabra reserbada que ingresó contiene los siguientes datos: "<<endl;
			cout<<endl;
			cout<<"Palabra en ingles: "<<pal<<endl;
				cout<<"Palabra en espaï¿½ol: "<<tra;
				getline(Lec,tralong);
					cout<<tralong<<endl;
						Lec>>def;
					cout<<"Definiciï¿½n: "<<def;
					getline(Lec,deflong);
					cout<<deflong<<endl;
					cout<<"---------------------------------------------------"<<endl;
			//Lec>>pal;
		
			 cout<<"Se eliminar�n todos los registros correspondientes a esta palabra reservada "<<endl;
			 
				cout<<"1. De acuerdo"<<endl;
				cout<<"2. No eliminar registros"<<endl;	
				cin>>opc;
				cout<<endl;
	
				if (opc!=1){
					cout<<"No se elimin� ning�n registro"<<endl;
								Lec.close();
								temp.close();
								remove("temp.txt");
								
						system("pause");
						int main();
						main();
				}			
			} 
		Lec>>pal;
			 	if(!Lec.eof()){ 
					//temp<<pal<<" "<<tra<<" "<<def<<" "<<deflong<<endl;	
				temp<<pal<<endl;
				Lec>>tra;
						temp<<tra;
						fflush(stdin);
				getline(Lec,tralong);
						temp<<tralong<<endl;
				Lec>>def;
						temp<<def;
						fflush(stdin);
				getline(Lec,deflong);
						temp<<deflong<<endl;
				
						}	
		}
		//Lec.close();
		//temp.close();
		
	}else{
	cout<<"Error no se pudo encontrar el archivo."<<endl;
}
		Lec.close();
		temp.close();
		fflush(stdin);
	remove("PAlabras.txt");
	rename("temp.txt","PAlabras.txt");	
cout<<"*********El registro se ha eliminado exitosamente**********"<<endl;	

			system("pause");		
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
		remove("texto_a_traducir.txt");
		string palabrat;
		ofstream Esct;

		Esct.open("texto_a_traducir.txt",ios::out);

		cout<<"TRADUCTOR"<<endl;
		cout<<"----------"<<endl;
cout<<"Ingrese la porci�n de c�digo que desea traducir:"<<endl;
	
		while(palabrat !="$"){
		getline(cin,palabrat);
		Esct<<palabrat<<endl;
		}

		Esct.close();
proceso();
 }


void proceso(){
	string palg;
	string Busqueda;
	string linea, lineal;	
	ifstream Esct;
	ofstream Lect;
	ifstream Lec;

 Esct.open("texto_a_traducir.txt",ios::in );
	Lect.open("Texto Traducido",ios::out);
		Lec.open("PAlabras.txt",ios::in );


 while(!Esct.eof()){

	Esct>>linea;

while(!Lec.eof()){

	Lec>>Busqueda;

//cout<<linea<<endl;
//cout<<Busqueda<<endl;
//	cout<<endl;


if (linea==Busqueda){

Lec>>Busqueda;

Lect<<Busqueda<<endl;

	
}
}




}

Lect.close();

Lec.close();
remove("texto_a_traducir.txt");
motstrar_traduccion();
}


void motstrar_traduccion(){
string texto;
ifstream Lect;


Lect.open("Texto Traducido",ios::out);

 Lect>>texto;
cout<<"------texto traducido--------"<<endl;
cout<<texto<<endl;

Lect.close();

remove("Texto Traducido");
remove("texto_a_traducir.txt");
system("pause");
menuinit();


}





	void Editar(){
		iniciado = false;
		int main();
		main();
	}

void menuinit(){
remove("texto_a_traducir.txt");
	system("cls");

		setlocale(LC_ALL, "Spanish");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	
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
            	//	system("agregar.exe");
            	break;
        		case 3:
            	break;
            		default:
            			error();
        	}
    	}	
    while(seleccion!=3);

	
	}

int main(){
while (iniciado == true){	
 menuinit();
}
	setlocale(LC_ALL, "Spanish");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	ofstream Esc;
	ifstream Lec;
	int op;
	do{
		system("cls");
		op= menu();
		switch (op){
		case 1: agregar(Esc);
		break;
		case 2: ver(Lec); 
		break;
		case 3: bus(Lec); 
		break;
		case 4: edit(Lec); 
		break;
		case 5: elim(Lec); 
		break;
		}
				
	}while(op!=6);
	system("cls");
menuinit();	
return 0;	
}



//#include "mprincipal.h"
#include<locale.h>
#include<iostream>
#include<fstream>
#include <windows.h>
using namespace std;

int menu(){
	int x;
	cout<<"-----------Bienvenido------------"<<endl;
	cout<<"1. Agregar registro"<<endl;
	cout<<"2. Ver registros"<<endl;
	cout<<"3. Buscar registro"<<endl;
	cout<<"4. Editar registro"<<endl;
	cout<<"5. Eliminar registro"<<endl;
	cout<<"6. Salir"<<endl;

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
	cout<<"Ingrese traducci�n"<<endl;
	cin>>Tra;
		fflush(stdin);
	cout<<"Ingrese la definici�n"<<endl;
	getline(cin,Def);
	

	
	es<<Pal<<" "<<Tra<<" "<<Def<<endl;
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
				cout<<"Palabra en espa�ol: "<<tra;
				getline(Lec,tralong);
					cout<<tralong<<endl;
					
						Lec>>def;
					cout<<"Definici�n: "<<def;
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
	string pal,ing,def,id,deflong;
	
	bool encontrado = false;
	
	cout<<"Ingrese la palabra que desea buscar"<<endl;
	cin>>id;
	Lec>>pal;
	
	while(pal != id && !Lec.eof()){
		Lec>>pal;
		
	}
	
	
		while(!Lec.eof()){
		Lec>>ing;
		Lec>>def;
	
		if(pal == id){
				cout<<"Palabra en ingles:  "<<pal<<endl;
				cout<<"Palabra en espa�ol: "<<ing<<endl;
				cout<<"Definici�n:         "<<def;
			
			getline(Lec,deflong);
				cout<<deflong<<endl;
				cout<<"-----------------------------------------------------"<<endl;	
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
	string tra;
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
			Lec>>def;
				if(pal != id){
					getline(Lec,deflong);
					temp<<pal<<" "<<tra<<" "<<def<<" "<<deflong<<endl;
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
			Lec>>def;
				cout<<endl;
				cout<<"La palabra reservada que ingres� contiene los siguientes registros: "<<endl;
				cout<<endl;
				cout<<"Palabra reservada:       "<<pal<<endl;
				cout<<"Traducci�n:              "<<tra<<endl;
				cout<<"Definici�n:        	    "<<def;
				getline(Lec,deflong);
				cout<<deflong<<endl;
				cout<<"--------------------------"<<endl;
				
					cout<<"INSTRUCCIONES: Ingrese los nuevos registros que se solicitan a continuacion, "<<endl;
				cout<<"si no desea editar alguno, debe ingresarlo igual nuevamente cuando se le solicite"<<endl;
				
				cout<<"Digite la nueva palabra reservada "<<endl;
				cin>>pal2;
				
				cout<<"Digite la nueva traducci�n "<<endl;
				cin>>tra2;
				fflush(stdin);
				cout<<"Digite la nueva definici�n "<<endl;
				getline(cin,def2);
	
					temp<<pal2<<" "<<tra2<<" "<<def2<<" "<<endl;	
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
			Lec>>tra;
			Lec>>def;
			 	getline(Lec,deflong);
			 	if(!Lec.eof()){
				 
					temp<<pal<<" "<<tra<<" "<<def<<" "<<deflong<<endl;	
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
	string tra;
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
			Lec>>def;
				if(pal != id){
					getline(Lec,deflong);
					temp<<pal<<" "<<tra<<" "<<def<<" "<<deflong<<endl;
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
			Lec>>def;
				cout<<endl;
				cout<<"La palabra reservada que ingres� contiene los siguientes registros: "<<endl;
				cout<<endl;
				cout<<"Palabra reservada:       "<<pal<<endl;
				cout<<"Traducci�n:              "<<tra<<endl;
				cout<<"Definici�n:        	    "<<def;
				getline(Lec,deflong);
				cout<<deflong<<endl;
				cout<<"--------------------------"<<endl;
		
			 cout<<"Se eliminar�n todos los registros correspondientes a esta palabra reservada "<<endl;
			 
				cout<<"1. De acuerdo"<<endl;
				cout<<"2. No eliminar registros"<<endl;	
				cin>>opc;
				cout<<endl;
	
				if (opc!=1){
					cout<<"No se elimin� ning�n registro"<<endl;
						temp.close();
								remove("temp.txt");
								
						system("pause");
						int main();
						main();
				}			
			} 
		Lec>>pal;
			Lec>>tra;
			Lec>>def;
			 	getline(Lec,deflong);
			 	if(!Lec.eof()){
				 
					temp<<pal<<" "<<tra<<" "<<def<<" "<<deflong<<endl;	
						}
				
		}
		Lec.close();
		temp.close();
		
	}else{
	cout<<"Error no se pudo encontrar el archivo."<<endl;
}
	
	remove("PAlabras.txt");
	rename("temp.txt","PAlabras.txt");	
cout<<"*********El registro se ha eliminado exitosamente**********"<<endl;	

			system("pause");		
 } 



int main(){
	
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
exit(1);	
return 0;	
}



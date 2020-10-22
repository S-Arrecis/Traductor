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
	cout<<"4. editar regisro"<<endl;
	cout<<"5. eliminar regisro"<<endl;
	cout<<"6. salir"<<endl;

	cout<< "Opcion: ";
	cin>>x;
	return x;
}


void agregar(ofstream &es) {
system("cls");	
	string Pal;
	string Tra;
	string Def;	
	es.open("PAlabras.txt",ios::out|ios::app);
	cout<<"INgrese palabra en reservada"<<endl;
	cin>>Pal;
	cout<<"Ingrese traduccion"<<endl;
	cin>>Tra;
	cout<<"ingrede la definición"<<endl;
	cin>>Def;
	es<<Pal<<" "<<Tra<<" "<<Def<<endl;
	es.close();
	 cout<< "****los registros han sido añadidos excitosamente*****"<<endl;
	
	system("pause");
}

void ver(ifstream &Lec){
	system("cls");
	string pal;
	string tra;
	string def;
	Lec.open("PAlabras.txt",ios::in);
	if(Lec.is_open()){
		Lec>>pal;
		while (!Lec.eof()){
			Lec>>tra;
			Lec>>def;
			cout<<"palabra en ingles: "<<pal<<endl;
				cout<<"palabra en español: "<<tra<<endl;
					cout<<"definicion: "<<def<<endl;
					cout<<"----------------"<<endl;
			Lec>>pal;
			
		}
		Lec.close();
			}else
			cout<<"Error,No se pudo abrir el archivo, es probable que el archivo no exita"<<endl; 
	system("pause");
	;
		
}

void  bus(ifstream &Lec){
	system("cls");
	Lec.open("PAlabras.txt",ios::in);
	string pal,ing,def,id;
	bool encontrado = false;
	cout<<"ingrese la palabra que desea buscar"<<endl;
	cin>>id;
	Lec>>pal;
	while(!Lec.eof()&& !encontrado){
		Lec>>ing;
		Lec>>def;
		
		if(pal == id){
				cout<<"palabra en ingles "<<pal<<endl;
				cout<<"palabra en español "<<ing<<endl;
				cout<<"definicion "<<def<<endl;
				cout<<"----------------"<<endl;	
			encontrado = true;
		}
		
		Lec>>pal;	
	}
	Lec.close();
	if (!encontrado)
	cout<<"dato no encontrado"<<endl;
	system("pause");
} 

void edit(ifstream & Lec){
		system("cls");
		
		cout<<"**********Editar Registros**********"<<endl;
		cout<<endl;
	string pal;
	string tra;
	string def;
	string id;
	string pal2,tra2,def2;
	Lec.open("PAlabras.txt",ios::in );
	ofstream temp("temp.txt",ios::out);
	if(Lec.is_open()){
		cout<<"Dijite el la palabra reservada del registro que desea editar"<<endl;
		cin>>id;

		
		Lec>>pal;
		while(!Lec.eof()){
			
			Lec>>tra;
			Lec>>def;
			
			if(pal == id){
				cout<<endl;
				cout<<"la palabra reservada que ingreso contine los siguientes registros: "<<endl;
				cout<<endl;
				cout<<"palabra reservada:       "<<pal<<endl;
				cout<<"traducción:              "<<tra<<endl;
				cout<<"definicion:              "<<def<<endl;
				cout<<"--------------------------"<<endl;	
				
				cout<<"INSTRUCCIONES: Ingreso los nuevos registros que se solicitan a conntinuacion, "<<endl;
				cout<<"si no desea editar alguno, debe ingresarlo igual nuevamente cuando se le solicite"<<endl;
				
				cout<<"dijite la nueva palabra reserbada "<<endl;
				cin>>pal2;
				
				cout<<"dijite la nueva traduccion "<<endl;
				cin>>tra2;
				fflush(stdin);
				cout<<"dijite la nueva definicion "<<endl;
				getline(cin,def2);
				
			//cin>>def2;
				
				temp<<pal2<<" "<<tra2<<" "<<def2<<endl;
				cout<<endl;

				
				cout<<"*********El registro se ah modificado excitosamente**********"<<endl;
				
			system("pause");
				
			} else{
		temp<<pal<<" "<<tra<<" "<<def<<endl;
			}
			
				Lec>>pal;
			
		}
		Lec.close();
		temp.close();
		
	}else
	
	cout<<"error"<<endl;
	remove("PAlabras.txt");
	rename("temp.txt","PAlabras.txt");
		
}
	

void elim(ifstream &Lec){
	
	system("cls");
		
		cout<<"**********Eliminar Registros**********"<<endl;
		cout<<endl;
	string pal;
	string tra;
	string def;
	string id;
	string pal2,tra2,def2;
	int opc;
	Lec.open("PAlabras.txt",ios::in );
	ofstream temp("temp.txt",ios::out);
	if(Lec.is_open()){
		cout<<"Dijite el la palabra reservada del registro que desea eliminar"<<endl;
		cin>>id;
		
		Lec>>pal;
		while(!Lec.eof()){
			
			Lec>>tra;
			Lec>>def;
			
			if(pal == id){
				cout<<endl;
				cout<<"la palabra reservada que ingreso contine los siguientes registros: "<<endl;
				cout<<endl;
				cout<<"palabra reservada:       "<<pal<<endl;
				cout<<"traducción:              "<<tra<<endl;
				cout<<"definicion:              "<<def<<endl;
				cout<<"--------------------------"<<endl;	
				
			 cout<<"se eliminaran todos los registros correspondientes a esta palabra reservada "<<endl;
			 
				cout<<"1. Deacuerdo"<<endl;
				cout<<"2. No eliminar nada"<<endl;	
				cin>>opc;
				cout<<endl;
			if(opc != 1){

			}
			

				cout<<"*********El registro se ah eliminado excitosamente**********"<<endl;	
			system("pause");
		
			} else{
		temp<<pal<<" "<<tra<<" "<<def<<endl;
			}
			
				Lec>>pal;
			
		}
		Lec.close();
		temp.close();
		
	}else
	
	cout<<"error"<<endl;
	remove("PAlabras.txt");
	rename("temp.txt","PAlabras.txt");	
			
}


int main(){
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
	
return 0;	
}

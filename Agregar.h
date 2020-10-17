#include<fstream>
#include<iostream>
#include <string.h>
using namespace std;

fstream P_Ingles,P_Espa,Palabras;
void abrir(){
	string contenido;
    int cont=0;
    string aux;
    P_Ingles >> aux;
	P_Ingles.open("ingles//Ingles.txt",ios::in);
	if (P_Ingles.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
         
         
		while(!P_Ingles.eof()){

            
            getline(P_Ingles,contenido);
			cout<<contenido<<endl;
            cont++;
              
        }
        
	}
    cout<<"Total de palabras> "<<cont-1<<endl;
	P_Ingles.close();
}

void buscar1(fstream &P_Espa,int lugar,string ing){
	string contenido;
    int cont=0,pos=0;
    bool encontrar = false;
    string aux;
    
	P_Espa.open("traduccion//traduccion.txt",ios::in);
	if (P_Espa.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
         
         
		while(!P_Espa.eof()||encontrar == true){

            
            getline(P_Espa,contenido);
			
            if(cont == lugar){
                cout<<ing<<" = "<<contenido<<"  \t..."<<endl;
                encontrar = true;
                
                exit(1);
            }
            cont++;  
        }

        
	}
    
    
	P_Espa.close();
}




void buscar(fstream &P_Ingles,string busqueda){
	string contenido;
    int cont=0,pos=0;
    bool encontrar = false;
    string aux;
    
	P_Ingles.open("ingles//Ingles.txt",ios::in);
	if (P_Ingles.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
         
         
		while(!P_Ingles.eof()||encontrar == true){

            
            getline(P_Ingles,contenido);
			//cout<<contenido<<endl;
            //cont++;
            if(contenido == busqueda){
                pos = cont;
                encontrar = true;
                cout<<pos<<"\n\n"<<endl;
                cont=0;
                buscar1(P_Espa,pos,contenido);
            }
            cont++;  
        }
        
	}
    cout<<"Total de palabras> "<<cont-1<<endl;
	P_Ingles.close();
}



    void iniciar(){
        /*
        system("@echo off mkdir traduccion");
        system("@echo off mkdir ingles");
        system("@echo off mkdir palabras");*/
        system(" mkdir traduccion");
        system(" mkdir ingles");
        system(" mkdir palabras");
    }

    void agregarPalabras(string espa,string ing,string def){
        Palabras.open("palabras//palabras.txt",ios::app);

        if(Palabras.fail()){
            cout<<"No es posible agregar la palabra.\n"<<endl;
            system("pause");
        }
        else{
            Palabras<<ing<<endl;
            Palabras<<espa<<endl;
            Palabras<<def<<endl;
            
        }
        cout<<"\n\tPalabra agregadas con exito..\n"<<endl;
        system("pause");
        
    }

    void agregarEspa(string espa){
        P_Espa.open("traduccion//traduccion.txt",ios::app);

        if(P_Espa.fail()){
            cout<<"No es posible agregar la palabra.\n"<<endl;
            system("pause");
        }
        else{
            
           P_Espa<<espa<<endl;
          
        }
        P_Espa.close();
    }

    void agregarIngles(string ing ){
        P_Ingles.open("ingles//Ingles.txt",ios::app);

        if(P_Ingles.fail()){
            cout<<"No es posible agregar la palabra.\n"<<endl;
            system("pause");
        }
        else{
            P_Ingles<<ing<<endl;
            
        }
        P_Ingles.close();
    }
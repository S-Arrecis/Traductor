#include<fstream>
#include<iostream>
#include <string.h>
using namespace std;

//variables para los archivos de texto
fstream P_Ingles,P_Espa,Palabras;

void traducir(){
    string coleccion[100],coleccionEspa[100],aux;
    string palabra,letra,temporal;
    int contador=0;

    while (letra !="$"){
        cin>>letra;
        
        palabra +=" ";
        palabra += letra;
        temporal+=letra;
        coleccion[contador]=palabra;
        palabra ="";
        contador++;
        
    }
     cout<<temporal<<"\n\n"<<endl;
   

   for(int i=0;i<contador;i++){
      cout<<coleccion[i]<<endl;
      //buscarIngles(P_Ingles,coleccion[i]);
    }
}

void eliminarTraduccion(fstream &P_Espa , string borrar){
    string contenido;
    fstream aux;
    aux.open("temp.txt",ios::app);
    //P_Espa >> borrar;

    P_Espa.open("traduccion.txt",ios::in);
	if (P_Espa.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);

    }
    else{
        while(!P_Espa.eof()){
            
            getline(P_Espa,contenido);
            //cout<<contenido<<endl;
            if(contenido == borrar){
                
                /*
                Palabras<<"";
                Palabras<<"";
                Palabras<<"";
                exit(1);*/
            }
            else{
                aux<<contenido<<endl;
            }
        }
    }

    P_Espa.close();
    aux.close();
    remove("traduccion.txt");
    rename("temp.txt","traduccion.txt");

}


void eliminarIngles(fstream &P_Ingles , string borrar){
    string contenido;
    fstream aux;
    aux.open("tempIng.txt",ios::app);

    P_Ingles.open("Ingles.txt",ios::in);
	if (P_Ingles.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);

    }
    else{
        while(!P_Ingles.eof()){
            
            getline(P_Ingles,contenido);
            //cout<<contenido<<endl;
            if(contenido == borrar){
                
                /*
                Palabras<<"";
                Palabras<<"";
                Palabras<<"";
                exit(1);*/
            }
            else{
                aux<<contenido<<endl;
            }
        }
    }

    P_Ingles.close();
    aux.close();
    remove("Ingles.txt");
    rename("tempIng.txt","Ingles.txt");

}


//abrir el archivo de texto con las palabras en ingles
void abrirIngles(){
	string contenido;
    int cont=0;
    string aux;
    P_Ingles >> aux;
	P_Ingles.open("Ingles.txt",ios::in);
	if (P_Ingles.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
         
         
		while(!P_Ingles.eof()){

            
            getline(P_Ingles,contenido);
			
             if(contenido !=""){
                cout<<contenido<<endl;
                cont++;
            }
            else{
			//cont++;
            } 
              
        }
        
	}
    cout<<"Total de palabras> "<<cont<<endl;
	P_Ingles.close();
}


void abrirTraduccion(){
	string contenido;
    int cont=0;
    string aux;
    //P_Ingles >> aux;
	P_Espa.open("traduccion.txt",ios::in);
	if (P_Espa.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
         
         
		while(!P_Espa.eof()){

            
            getline(P_Espa,contenido);
            if(contenido !=""){
                cout<<contenido<<endl;
                cont++;
            }
            else{
			//cont++;
            }  
        }
        
	}
    cout<<"Total de palabras> "<<cont<<endl;
	P_Espa.close();
}

void buscarTraduccion(fstream &P_Espa,int lugar,string ing){
	string contenido;
    int cont=0,pos=0;
    bool encontrar = false;
    string aux;
    
	P_Espa.open("traduccion.txt",ios::in);
	if (P_Espa.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
         
         
		while(!P_Espa.eof()||encontrar == true){

            
            getline(P_Espa,contenido);
			
            if(cont == lugar){
                cout<<ing<<" = "<<contenido<<"  \t..."<<endl;
                encontrar = true;
                break;
                //exit(1);
            }
            cont++;  
        }

        
	}
    
    
	P_Espa.close();
}




void buscarIngles(fstream &P_Ingles,string busqueda){
	string contenido;
    int cont=0,pos=0;
    bool encontrar = false;
    string aux;
    
	P_Ingles.open("Ingles.txt",ios::in);
	if (P_Ingles.fail()){
		cout<<"No es posible abrir el archivo";
		exit(1);
	}else{
         
         
		while(!P_Ingles.eof()||encontrar == true){

            
            getline(P_Ingles,contenido);

            if(contenido == busqueda){
                pos = cont;
                encontrar = true;
                cont=0;
                buscarTraduccion(P_Espa,pos,contenido);
            }
            cont++;  
        }
        
	}
    
	P_Ingles.close();
}



    void iniciar(){
        /*
        system("@echo off mkdir  traduccion");
        system("@echo off mkdir ingles");
        system("@echo off mkdir palabras");*/
        system(" mkdir traduccion");
        system(" mkdir ingles");
        system(" mkdir palabras");
    }

    void agregarPalabras(string ing,string espa,string def){
        Palabras.open("palabras.txt",ios::app);

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

    void agregarTraduccion(string espa){
        P_Espa.open("traduccion.txt",ios::app);

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
        P_Ingles.open("Ingles.txt",ios::app);

        if(P_Ingles.fail()){
            cout<<"No es posible agregar la palabra.\n"<<endl;
            system("pause");
        }
        else{
            P_Ingles<<ing<<endl;
            
        }
        P_Ingles.close();
    }

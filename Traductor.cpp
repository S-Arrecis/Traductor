#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>

using namespace std;

class menu
{
private:
	string palabra;
	string traduccion;
	string funcionalidad;
	
public:
	void menuP();
	void NuevaPalabra();
	void VerPalabra();
	void ModificarPalabra();
	void EliminarPalabra();
	void MostrarPalabras();	
};
void pausa()
{
    cout<<"Presiona enter para continuar...";
    getch();
    system("cls");
}
void error()
{
    cout<<"Error";
}
void menu::menuP()
{
    int opcion;
    do
    {
        cout<<"Proyecto Traductor"<<endl;
        cout<<"1. Ingresar una nueva palabra"<<endl;
        cout<<"2. Buscar palabra"<<endl;
        cout<<"3. Modificar Palabra"<<endl;
        cout<<"4. Eliminar palabra"<<endl;
        cout<<"5. Mostrar todas las palabras registradas"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        default:
            cout<<"Opcion no valida";
            break;

        case 1:
            NuevaPalabra();
            break;

        case 2:
            VerPalabra();
            break;

        case 3:
            ModificarPalabra();
            break;

        case 4:
            EliminarPalabra();
            break;

        case 5:
        	MostrarPalabras();
            break;
        
        case 6:
        	break;
        }
    }
    while(opcion!=6);
}


void menu::NuevaPalabra()
{
    ofstream escritura;
    escritura.open("palabras.txt",ios::app);
    if(escritura.is_open())
    {
    	fflush(stdin);
       cout<<"Ingresa nueva palabra: ";
        getline(cin ,palabra);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la traduccion: ";
        getline(cin,traduccion);
        cout<<"\n\n";
         fflush(stdin);
        cout<<"Ingresa la funcionalidad: " ;
        getline(cin,funcionalidad);
        cout<<"\n\n";
       
        escritura<<palabra<<"\n"<<traduccion<<"\n"<<funcionalidad<<"\n";

        cout<<"El registro se ha completado correctamente";
    }

    else
    {
        error();
    }

    escritura.close();
    pausa();
}
void menu::VerPalabra()
{
    string vpalabra;
    ifstream mostrar;
    bool encontrado=false;
    mostrar.open("palabras.txt",ios::in);
    if(mostrar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa la palabra que desea traducir: ";
        getline(cin,vpalabra);
        getline(mostrar,palabra);
        while(!mostrar.eof())
        {
            getline(mostrar,traduccion);
            getline(mostrar,funcionalidad);

            if(vpalabra==palabra)
            {
                encontrado=true;
                cout<<"Registro Encontrado";
                cout<<"Palabra: "<<palabra<<endl;
                cout<<"Traduccion: "<<traduccion<<endl;
                cout<<"Funcionalidad: "<<funcionalidad<<endl;
                cout<<"\n\n";
            }

            getline(mostrar,palabra);
        }

        if(encontrado==false)
        {
            cout<<"No se encontro la palabra "<<vpalabra<<endl;
        }
    }

    else
    {
        error();
    }

    mostrar.close();
    pausa();
}
void menu::ModificarPalabra(){
}
void menu::EliminarPalabra(){
}

void menu::MostrarPalabras(){
	   int i=0;
    ifstream lectura;
    lectura.open("palabras.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"Listado de todas las palabras registradas\n\n"<<endl;
        while(!lectura.eof())
        {
            i++;
            getline(lectura,palabra);
            getline(lectura,traduccion);
            getline(lectura,funcionalidad);
            cout<<"Palabra: "<<palabra<<endl;
            cout<<"Traduccion: "<<traduccion<<endl;
            cout<<"Funcionalidad: "<<funcionalidad<<endl;
                cout<<"\n\n";
        }
            cout<<"Hay un total de "<<i<<" registros encontrados"<<endl;
    }
    else
    {
        error();
    }
    lectura.close();
    pausa();
}

int main()
{
    menu inicio;
    inicio.menuP();
    return 0;
}


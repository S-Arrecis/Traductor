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
};
void pausa()
{
    cout<<"Presiona enter para continuar...";
    getch();
    system("cls");
}
void error()
{
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"clientes.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
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
        cout<<"5. Salir"<<endl;
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
            break;
        }
    }
    while(opcion!=5);
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
       
        escritura<<palabra<<"\n\n"<<traduccion<<"\n\n"<<funcionalidad<<"\n\n";

        cout<<"El registro se ha completado correctamente.\n\n";
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
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"Palabra: "<<palabra<<endl;
                cout<<"Traduccion: "<<traduccion<<endl;
                cout<<"Funcionalidad: "<<funcionalidad<<endl;
                cout<<"\n\n";
            }

            getline(mostrar,palabra);
        }

        if(encontrado==false)
        {
            cout<<"No se encontro la palabra: "<<vpalabra<<"\n\n";
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

int main()
{
    menu inicio;
    inicio.menuP();
    return 0;
}


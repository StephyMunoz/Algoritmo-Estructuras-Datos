#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void escribir();
void leer();

int main()
{
    int opcion;
    cout<<"-------------------MENU--------------------"<<endl;
    cout<<"\n1. INGRESAR LA INFORMACION DE CONTACTOS "<<endl;
    cout<<"\n2. LEER LA INFORMACION "<<endl;
    cout<<"\nINGRESE LA OPCION: ";
    cin>>opcion;
    cout<<endl;
    switch(opcion)
    {

    case 1:
          escribir();
        break;
    case 2:
        leer();
        break;
    default:
    cout<<"OPCION INCORRECTA";
        break;

    }
    return 0;
}

void escribir()
{
    string nombre, apellido, nombre_archivo;
    int edad;
    char r;
    ofstream archivo;

    cout<<"INGRESE EL NOMBRE DEL ARCHIVO: ";
    getline(cin,nombre_archivo);
    archivo.open(nombre_archivo.c_str(),ios::out);

    do
    {

      cout<<"\nINGRESE EL NOMBRE: ";
      getline(cin,nombre,'\n');
      cout<<"\nINGRESE EL APELLIDO: ";
      getline(cin,apellido,'\n');
      cout<<"\nINGRESE LA EDAD: ";
      cin>>edad;
      archivo<<nombre<<"  "<<apellido<<"  "<<edad<<"\n";
      cout<<"\nDESEA INGRESAR LA INFORMACION DE OTRO CONTACTO (s/n): ";
      cin>>r;
cin.ignore();
    }
    while(r=='s');

    if(archivo.fail())
    {
        cout<<"EL ARCHIVO NO HA SIDO CREADO ";
        exit(1);
    }

    archivo.close();
}
void leer()
{
    cout<<endl<<" IMPRESION "<<endl<<endl;
    ifstream archivo_lectura("agenda.txt");
    string texto,nombre,apellido;
    int edad;
    do
    {
        archivo_lectura>>nombre>>apellido>>edad;
        if(!archivo_lectura.eof())
        {
            getline(archivo_lectura,texto);
            cout << "Nombre: " << nombre << endl;
            cout << "Apellido: " << apellido << endl;
            cout << "Edad: " << edad <<endl << endl;
        }
    }
    while(!archivo_lectura.eof());
    archivo_lectura.close();
}

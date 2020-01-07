#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
void ingresar(int a[],int n);
void imprimir(int a[],int n);
void comparar(int a[],int n,int dato);
void guardar(int a[],int n, int dato);

int main()

{

    setlocale(LC_CTYPE,"Spanish");
    int n,dato;
    cout<<"Ingrese el tamaño del arreglo: ";
    cin>>n;
    int a[n];
    ingresar(a,n);
    cout<<"Ingrese el elemento a buscar: ";
    cin>>dato;
    comparar(a,n,dato);
    cout<<"\nEl arreglo es: ";
    imprimir(a,n);
    guardar(a,n,dato);
    return 0;
}
void ingresar(int a[],int n)
{

    for(int i=0; i<n; i++)
    {
        cout<<"\nIngrese el elemento "<<i+1<<" del arreglo: ";
        cin>>a[i];
        //cout<<endl;
    }
}
void imprimir(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<"|";

    }
    cout<<endl;
}
void comparar(int a[],int n,int dato)
{
    bool c;
    c=false;

    for(int i=0; i<n; i++)
    {
        if(a[i]==dato)
        {
            cout<<"\nELMENTO ENCONTRADO: ";
            cout<<"\nEN LA POSICIÒN: "<<i<<endl;
            c=true;

        }

    }
    if(c==false)
    {
        cout<<"\nELMENTO NO ENCONTRADO: ";
    }
}
void guardar(int a[],int n,int dato)
{

    bool c;
    ofstream archivo;
    cin.ignore();
    string nombreA;
    cout<<"Ingrese el nombre del archivo: ";
    getline(cin,nombreA);
    archivo.open(nombreA.c_str(),ios::out);
    c=false;
    for(int i=0; i<n; i++)
    {
        if(a[i]==dato)
        {
            archivo<<"\nELMENTO ENCONTRADO: ";
            archivo<<"\nEN LA POSICIÒN: "<<i<<endl;
            c=true;

        }

    }
    if(c==false)
    {
        archivo<<"\nELMENTO NO ENCONTRADO: ";
    }
    archivo<<"\n";
    archivo<<"EL ARREGLO ES: ";
    for(int i=0; i<n; i++)
    {
        archivo<<a[i]<<"|";

    }
}

#include <iostream>

using namespace std;

void ingresar(int a[],int n);
void ordenar(int a[],int n);
void imprimir (int a[],int n);

int main()
{
    int n;
    do
    {
     cout<<"Ingrese el tamano del arreglo: ";
    cin>>n;
    }
    while(n<=0);

    int a[n];
    ingresar(a,n);
    ordenar(a,n);
    imprimir(a,n);

    return 0;
}
void ingresar(int a[],int n)
{
     for(int i=0;i<n;i++)
    {
        cout<<"\nIngrese el elemento "<<i+1<<" del arreglo: ";
        cin>>a[i];
    }
}
void ordenar(int a[],int n)
{
    int i,pos,aux;
    for(i=0;i<n;i++)
    {
        pos=i;
        aux=a[i];
        while((pos>0)&&(a[pos-1])>aux)
        {
            a[pos]=a[pos-1];
            pos--;
        }
        a[pos]=aux;
    }
}
void imprimir (int a[],int n)
{
     for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

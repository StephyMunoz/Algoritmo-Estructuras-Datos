#include <iostream>

using namespace std;
void agregar(int a[],int n);
void imprimir(int a[],int n);
void menor(int a[],int n);

int main()
{
   int n;

   cout<<"Ingrese el tamaño del arreglo: ";
   cin>>n;
   int arreglo[n];
   agregar(arreglo,n);
   menor(arreglo,n);
   imprimir(arreglo,n);
    return 0;
}
void agregar(int a [], int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<"INGRESE EL ELEMENTO "<<i<<" : ";
        cin>>a[i];
    }
}

void menor(int a [], int n)
{
    int aux, min;
      for(int i=0;i<5;i++)
    {
        min=i;
        for(int j=i+1;j<5;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        aux=a[i];
        a[i]=a[min];
        a[min]=aux;
    }
}

void imprimir(int a [], int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

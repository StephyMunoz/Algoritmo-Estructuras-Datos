#include <iostream>
#include <fstream>

using namespace std;

int mitad (int a[],int pinicial,int pfinal);
void ordenar(int a[],int pinicial,int pfinal);
void archivo(int a[],int pinicial,int pfinal);

int main()
{
    int a[10]= {-123,-6,13,-33,-98,333,23,-5,0,-100};
    cout<<"El arreglo original es: "<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<"|"<<a[i]<<"|";
    }
    cout<<endl;
    archivo(a,0,9);
    ordenar(a,0,9);
    cout<<"\nEl arreglo ordenado es: "<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<"|"<<a[i]<<"|";
    }

               return 0;
}

int mitad (int a[],int pinicial,int pfinal)
{
    return a[(pinicial+pfinal)/2];

}
void ordenar(int a[],int pinicial,int pfinal)
{
    int i=pinicial;
    int j=pfinal;
    int temp;
    int piv=mitad(a,pinicial,pfinal);

    do
    {
        while(a[i]<piv)
        {
            i++;
        }
        while(a[j]>piv)
        {
            j--;
        }
        if(i<=j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    }
    while(i<=j);

    if(pinicial<j)
    {
        ordenar(a,pinicial,j);
    }
    if(i<pfinal)
    {
        ordenar(a,i,pfinal);
    }
}
void archivo(int a[],int pinicial,int pfinal)
{
    int i=pinicial;
    int j=pfinal;
    int temp;
    int piv=mitad(a,pinicial,pfinal);
    ofstream quicksort;
    quicksort.open("archivo_quicksort.txt",ios::out);
    quicksort<<"Arreglo original: "<<endl;
    for(int i=0;i<10;i++)
    {
        quicksort<<"|"<<a[i]<<"|";
    }
    do
    {
        while(a[i]<piv)
        {
            i++;
        }
        while(a[j]>piv)
        {
            j--;
        }
        if(i<=j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    }
    while(i<=j);

    if(pinicial<j)
    {
        ordenar(a,pinicial,j);
    }
    if(i<pfinal)
    {
        ordenar(a,i,pfinal);
    }
    quicksort<<"\nArreglo ordenado: "<<endl;
    for(int i=0;i<10;i++)
    {
        quicksort<<"|"<<a[i]<<"|";
    }
    quicksort.close();
}

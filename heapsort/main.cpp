#include <iostream>

using namespace std;

#include "heapsort.h"
#include "ingresar.h"
#include "imprimir.h"

int main()
{
    int a[100],n;
    cout<<"Ingresa la cantidad de elementos del arreglo: ";
    cin>>n;
    ingresar(a,n);
    HeapSort(a,n);
    imprimir(a,n);
    return 0;
}

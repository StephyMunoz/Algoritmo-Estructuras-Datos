#include <iostream>

using namespace std;

int ingrese_dinero_cuenta (int dinero[], int n);
void ordenar_elementos(int dinero[],int n);
void mostrar_menor_mayor(int[],int n);
void mostrar_mayor_menor(int dinero [],int n);
int suma_pares(int dinero [],int n);
const int Max = 100;

int main()
{
    int opc, n;
    int cuentas[Max];
    setlocale(LC_CTYPE, "Spanish");

    cout << "¡BIENVENIDO!" << endl << endl;
    do
    {
        do
        {
            cout << endl << "Menú:" << endl;
            cout << "1.- Ingresar dinero a la cuenta" << endl;
            cout << "2.- Ordenar elementos del arreglo" << endl;
            cout << "3.- Mostrar elementos ordenados de menor a mayor" << endl;
            cout << "4.- Mostrar elementos ordenados de mayor a menor" << endl;
            cout << "5.- Suma pares e impares" <<endl;
            cout << "6.- Salir" << endl << endl;
            cout << "-> Introduzca una opción por favor: ";
            cin >> opc;
        }
        while (opc < 0 || opc > 6 );

        switch (opc)
        {
        case 1:
        {
            cout << "¿Cuántos depósitos desea realizar? ";
            cin >> n;
            ingrese_dinero_cuenta(cuentas, n);
            break;
        }

        case 2:
        {
            ordenar_elementos(cuentas,n);
            cout << "¡Los elementos han sido ordenados! Gracias por utilizar nuestro servicio" << endl;
            break;
        }

        case 3:
            mostrar_menor_mayor(cuentas,n);
            break;
        case 4:
            mostrar_mayor_menor(cuentas,n);
            break;
        case 5:
            suma_pares(cuentas,n);
            break;
        case 6:
            return 0;
            break;
        }
    }
    while(opc != 6);
}

int ingrese_dinero_cuenta (int dinero[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"INGRESE EL ELEMENTO "<<i + 1<<" DE LA CUENTA: ";
        cin>>dinero[i];
        while (dinero[i]<0)
        {
            cout<<"INGRESE UN VALOR POSITIVO DEL ELEMENTO "<<i + 1<<" : ";
            cin>>dinero[i];
        }
    }
    return dinero[5];
}
void ordenar_elementos(int dinero[],int n)
{
    for (int i=0; i<n;i++)
    {
        for (int j=i+1;j<=n-1;j++)
        {
            if(dinero[i]>dinero[j])
            {
                int aux=dinero[i];
                dinero[i]=dinero[j];
                dinero[j]=aux;
            }
        }
    }

}
void mostrar_menor_mayor(int dinero [],int n)
{
    cout<<"EL ARREGLO DE MENOR A MAYOR ES: ";
     for(int i = 0;i<n;i++)
    {
      cout<<dinero[i]<<" ";
    }
    cout<<endl;
}

void mostrar_mayor_menor(int dinero [],int n)
{
    cout<<"EL ARREGLO DE MAYOR A MENOR ES: ";
     for(int i=(n-1);i>=0;i=i-1)
    {
      cout<<dinero[i]<<" ";
    }
     cout<<endl;
}

int suma_pares(int dinero [],int n)
{
    int p = 0,imp=0;
    for(int i=0;i < n; i++)
    {
      if (dinero[i]%2 == 0)
      {
          p = p + dinero[i];
      }
      else
        {
        imp = imp + dinero[i];
        }
    }
    cout<<"La suma de los elementos pares es: "<<p<<endl;
    cout<<"La suma de los elementos impares es: "<<imp<<endl;
}



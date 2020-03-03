#include <iostream>
#include <fstream>
#include <stdlib.h> //Libreria para utilizar la funcion system
#include <direct.h> //Libreria para crear la carpeta colegio


using namespace std;

#include "ingresar.h"
#include "archivo_calificaciones.h"
#include "ordenar.h"
#include "archivo_ordenar.h"
#include "busqueda.h"
#include "archivo_busqueda.h"

int main()
{
    mkdir("colegio");
    int Max=150;
    setlocale(LC_CTYPE, "Spanish");
    bool c=false;
    int numero_estudiantes,n,m,medio,menu;
    double notas_buscar;
    string nombre_docente;
    string materia;
    double notas[Max];
    long int cedula;
    string nombres[Max];
    do
    {
        cout << endl << "Menú:" << endl;
        cout << "\n1.- Ingresar nombre del docente: " << endl;
        cout << "\n2.- Ingresar la materia: " << endl;
        cout << "\n3.- Ingresar el número de estudiantes a registrar: " << endl;
        cout << "\n4.- Ingresar las notas de cada estudiante: " << endl;
        cout << "\n5.- Almacenar los datos en un archivo: " <<endl;
        cout << "\n6.- Ordenar las calificaciones obtenidas: " <<endl;
        cout << "\n7.- Almacenar las calificaciones ordenadas en un archivo: " <<endl;
        cout << "\n8.- Buscar una calificación" <<endl;
        cout << "\n9.- Guardar la calificación buscada en un archivo " <<endl;
        cout << "\n10.- SALIR" <<endl;
        cout << endl;
        cout << "\nIngrese la opción que desee: ";
        cin >> n;
        //system ("cls");
        switch(n)
        {
        case 1:
        {
            cin.ignore();
            cout<<"\nIngrese el nombre del docente: ";
            getline(cin,nombre_docente);
            cout<<"\nIngrese el número de cédula del docente: ";
            cin>>cedula;


            break;
        }
        case 2:
            {

            cin.ignore();
            cout<<"\nIngrese el nombre de la materia: ";
            getline(cin,materia);

            }
            break;
        case 3:
        do
        {
            cout<<"\nIngrese el número de estudiantes a registrar: ";
            cin>>numero_estudiantes;
        }

        while(n<=0);
            break;

        case 4:
        {
            //Max=numero_estudiantes;
            ingresar_estudiantes(numero_estudiantes,nombres,notas);
            break;
        }


        case 5:
        {
            //Max=numero_estudiantes;
            archivo(numero_estudiantes,nombres,notas,nombre_docente,materia,cedula);
            break;
        }
        case 6:
        {
            do
            {
                cout<<"\nSeleccione el tipo de algoritmo con el que desea ordenar las calificaciones"<<endl;
                cout<<"\nOpcion 1. Ordenamiento Burbuja " <<endl;
                cout<<"\nOpcion 2. Ordenamiento por Selección " <<endl;
                cout<<"\nOpcion 3. Ordenamiento Merge Sort " <<endl;
                cout<<"\nOpcion 4. Ordenamiento Quick Sort " <<endl;
                cout<<"\nOpcion 5. Ordenamiento por Inserción " <<endl;
                cout<<"\nOpcion 6. Ordenamiento Heapsort "<<endl;
                cout<<"\nElija la opción que desea: ";
                cin>>m;
            }
            while((m<1)|(m>6));

            switch(m)
            {
            case 1:
                burbuja(notas,numero_estudiantes,nombres);
                break;
            case 2:
                ordenar_seleccion(notas,numero_estudiantes,nombres);
                break;
            case 3:
                medio=(numero_estudiantes)/2;
                dividir(notas,1,numero_estudiantes,numero_estudiantes,nombres);
                ordenar_mergesort(notas,1,numero_estudiantes,medio,numero_estudiantes,nombres);
                break;
            case 4:
                ordenar_quicksort(notas,1,numero_estudiantes,nombres);
                break;
            case 5:
                ordenar_insercion(notas,numero_estudiantes,nombres);
                break;
            case 6:
                HeapSort(notas,numero_estudiantes,nombres);

                break;
            }
        }
        break;
        case 7:
            archivo_ordenado(numero_estudiantes,notas,nombre_docente,cedula,m);
            break;
        case 8:
            do
            {
                cout<<"\nOpción 1: Búsqueda Lineal "<<endl;
                cout<<"\nOpción 2: Búsqueda Binaria "<<endl;
                cout<<"\nOpción 3: Búsqueda por Interpolación "<<endl;
                cout<<"\nIngrese la opción que desea: ";
                cin>>menu;
                cout<<"\nIngrese la calificación que desea buscar: ";
                cin>>notas_buscar;
            }
            while((menu<0)|(menu>3));
            switch (menu)
            {
            case 1:
               busqueda_lineal(notas,numero_estudiantes,notas_buscar,nombres);
                break;
                case 2:
                    {
                      busqueda_binaria(notas,numero_estudiantes,notas_buscar,nombres);
                    }

                    break;
                case 3:
                    {
                        busqueda_interpolacion(notas,numero_estudiantes,notas_buscar,nombres);
                    }

                    break;
            }
            break;
        case 9:
            archivo_busqueda(notas,numero_estudiantes,notas_buscar,nombres,menu,nombre_docente,cedula);
            break;
        }
    }
    while((n!=10)|(n<=0));

    return 0;
}

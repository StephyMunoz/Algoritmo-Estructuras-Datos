#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *derecho;
    Nodo *izquierdo;
};
//Nodos listos para ser insertados en el arbol
Nodo *crearNodoPadresHijos(int n);

//Arbol listo para ser usado
Nodo *arbolbinario = NULL;

void insertarNodosEnArbolBinario(Nodo *&arbolbinario,int n);
void mostrarArbolBinario(Nodo *&arbolbinario,int separador);
void preOrden (Nodo *&arbolBinario);
void posOrden (Nodo *&arbolBinario);
void inOrden (Nodo *&arbolBinario);

int main()
{
    int n;

    for(int i=0;i<9;i++)
    {
        cout<<"Insertar nodos: ";
        cin>>n;
        insertarNodosEnArbolBinario(arbolbinario,n);

    }
      mostrarArbolBinario(arbolbinario,0);
    cout<<"\nRECORRIDO EN PRE-ORDEN ES:"<<endl;
    preOrden(arbolbinario);
    cout<<endl;
    cout<<"\nRECORRIDO EN POS-ORDEN ES:"<<endl;
    posOrden(arbolbinario);
    cout<<endl;
    cout<<"\nRECORRIDO EN IN-ORDEN ES:"<<endl;
    inOrden(arbolbinario);
    cout<<endl;
    return 0;
}
Nodo *crearNodoPadresHijos(int n)
{
    //Inicializar el àrbol con los nodos
    Nodo *nuevo=new Nodo();
    //Asignar los valores al nodo creado (Instanciado)
    nuevo -> dato=n;
    nuevo -> derecho=NULL;
    nuevo -> izquierdo=NULL;

    return nuevo;
}

void insertarNodosEnArbolBinario(Nodo *&arbolbinario,int n)
{
    if(arbolbinario==NULL)
    {
        Nodo *nuevo = crearNodoPadresHijos(n);
        arbolbinario = nuevo;
    }
    else
    {
        //Insertar nodo raiz
        int datoRaiz = arbolbinario -> dato;
        if(n<datoRaiz)
        {
            //Insertar el siguiente nodo en el sub-izquierdo
            insertarNodosEnArbolBinario(arbolbinario->izquierdo,n);
        }
        else
        {
            //Insertar el siguiente nodo en el sub-dercho
            insertarNodosEnArbolBinario(arbolbinario->derecho,n);
        }
    }
}
void mostrarArbolBinario(Nodo *&arbolbinario,int separador)
{
    if(arbolbinario==NULL)
    {
        return;
    }
    else
    {

        mostrarArbolBinario(arbolbinario->derecho,separador+1);

        for(int i=0;i<separador;i++)
        {
            cout<<"   ";
        }
        cout<<arbolbinario->dato<<endl;
        mostrarArbolBinario(arbolbinario -> izquierdo , separador+1);
    }
}
void preOrden (Nodo *&arbolBinario)
{
     if (arbolBinario==NULL)
    {
       return;
    }
    else
    {
        cout<<arbolBinario->dato<<"-";
        preOrden(arbolBinario->izquierdo);
        preOrden(arbolBinario->derecho);
}
}
void posOrden (Nodo *&arbolBinario)
{
        if (arbolBinario==NULL)
    {
       return;
    }
    else
    {

        posOrden(arbolBinario->izquierdo);
        posOrden(arbolBinario->derecho);
        cout<<arbolBinario->dato<<"-";
}
}
void inOrden (Nodo *&arbolBinario)
{
            if (arbolBinario==NULL)
    {
       return;
    }
    else
    {

        inOrden(arbolBinario->izquierdo);
        cout<<arbolBinario->dato<<"-";
        inOrden(arbolBinario->derecho);

}
}

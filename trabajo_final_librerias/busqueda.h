bool busqueda_lineal(double notas[],int n,double dato,string nombres[])
{
    bool c;
    c=false;
    string aux;
    for(int i=1; i<=n; i++)
    {
        if(notas[i]==dato)
        {
            c=true;
            aux=nombres[i];

        }

    }

}
void busqueda_binaria(double notas[],int n, double dato,string nombres[])
{
    bool c=false;
    string aux;
    int mitad, inferior, superior;
    inferior=1;
    superior=n;
    while(inferior<=superior)
    {
        mitad=(superior+inferior)/2;
        if(notas[mitad]==dato)
        {
            c=true;
            aux=nombres[mitad];
            break;
        }
        if(notas[mitad]>dato)
        {
            superior=mitad-1;
        }
        if(notas[mitad]<dato)
        {
            inferior=mitad+1;
        }
    }
}
void busqueda_interpolacion(double notas[],int n,double num,string nombres[])
{
    int primero=0;
    int ultimo=n-1;
    int medio;
    int cont=0;

    while(notas[primero]!=num && cont<n)
    {
        medio=primero+((num-notas[primero])*(ultimo-primero)/(notas[ultimo]-notas[primero]));

        if(notas[medio]>num)
        {
            ultimo=medio-1;
        }
        else if(notas[medio]<num)
        {
            primero=medio+1;
        }
        else
        {
            primero=medio;
        }
        cont++;
        break;
    }
}

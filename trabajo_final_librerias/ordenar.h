void burbuja (double notas[], int n,string nombres[])
{
    for (int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            if (notas[i] > notas[j])
            {
                double aux = notas[i];
                string auxn=nombres[i];
                notas[i] = notas[j];
                nombres[i]=nombres[j];
                notas[j] = aux;
                nombres[j]=auxn;
            }
        }

    }
}
double mitad (double notas[],int pinicial,int pfinal)
{
    return notas[(pinicial+pfinal)/2];

}
void ordenar_quicksort(double notas[],int pinicial,int pfinal,string nombres[])
{
    string aux;
    int i=pinicial;
    int j=pfinal;
    double temp;
    double piv=mitad(notas,pinicial,pfinal);

    do
    {
        while(notas[i]<piv)
        {
            i++;
        }
        while(notas[j]>piv)
        {
            j--;
        }
        if(i<=j)
        {
            temp=notas[i];
            aux=nombres[i];
            notas[i]=notas[j];
            nombres[i]=nombres[j];
            notas[j]=temp;
            nombres[j]=aux;
            i++;
            j--;
        }
    }
    while(i<=j);

    if(pinicial<j)
    {
        ordenar_quicksort(notas,pinicial,j,nombres);
    }
    if(i<pfinal)
    {
        ordenar_quicksort(notas,i,pfinal,nombres);
    }

}
void ordenar_insercion(double notas[],int n,string nombres[])
{
    string auxn;
    int i,pos;
    double aux;
    for(i=1; i<=n; i++)
    {
        pos=i;
        aux=notas[i];
        auxn=nombres[i];
        while((pos>0)&&(notas[pos-1])>aux)
        {
            notas[pos]=notas[pos-1];
            nombres[pos]=nombres[pos-1];
            pos--;
        }
        notas[pos]=aux;
        nombres[pos]=auxn;
    }
}
void ordenar_seleccion(double notas[], int n,string nombres[])
{
    string auxn;
    int min;
    double aux;
    for(int i=1; i<=n; i++)
    {
        min=i;
        for(int j=i+1; j<=n; j++)
        {
            if(notas[j]<notas[min])
            {
                min=j;
            }
        }
        aux=notas[i];
        auxn=nombres[i];
        notas[i]=notas[min];
        nombres[i]=nombres[min];
        notas[min]=aux;
        nombres[min]=auxn;
    }
}
void ordenar_mergesort(double notas[],int pinicial,int pfinal,int medio,int n,string nombres[])
{
    int i,j,k;
    double temp[pfinal-pinicial+1];
    i=pinicial;
    k=0;
    j=medio+1;
    string aux[pfinal-pinicial+1];

//Tomar los elementos y ordenar el arreglo temp

    while(i<=medio && j<=pfinal)
    {
        if(notas[i]<notas[j])
        {
            temp[k]=notas[i];
            aux[k]=nombres[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=notas[j];
            aux[k]=nombres[j];
            k++;
            j++;
        }
    }

    //Almacenar los valors del arreglo sub-derecho

    while(i<=medio)
    {
        temp[k]=notas[i];
        aux[k]=nombres[i];
        k++;
        i++;
    }

    // Almacenar los valores del arreglo sub-izquierdo

    while(j<=pfinal)
    {
        temp[k]=notas[j];
        aux[k]=nombres[j];
        k++;
        j++;
    }
    for(i=pinicial; i<=pfinal; i++)
    {
        notas[i]=temp[i-pinicial];
        nombres[i]=aux[i-pinicial];
    }
}

void dividir(double notas[],int inicial,int final,int n,string nombres[])
{
    int mitad;
    if(inicial<final)
    {
        mitad=(inicial+final)/2;

        dividir(notas,inicial,mitad,n,nombres);
        dividir(notas,mitad+1,final,n,nombres);
        ordenar_mergesort(notas,inicial,final,mitad,n,nombres);
    }
}
void HeapSort(double b[], int n,string nombres[])
{
    double valor,temp;
    string valn,tempn;
    int a;

    for(int i=n; i>0; i--)
    {
        for(int j=1; j<=i; j++)
        {
            valor=b[j];
            valn=nombres[j];
            a=j/2;
            while(a>0 && b[a]<valor)
            {
                b[j]=b[a];
                nombres[j]=nombres[a];
                j=a;
                a=a/2;
            }
            b[j]=valor;
            nombres[j]=valn;
        }
        temp=b[1];
        tempn=nombres[1];
        b[1]=b[i];
        nombres[1]=nombres[i];
        b[i]=temp;
        nombres[i]=tempn;
    }

}


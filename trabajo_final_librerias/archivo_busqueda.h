
void archivo_busqueda(double notas[],int n, double notas_buscar,string nombres[],int menu,string profesor, long int cedula)
{
    ofstream archivo3;
    bool c=false;
    string aux;
    archivo3.open("colegio//búsqueda.txt",ios::out);

    archivo3<<"                                       COLEGIO MEJIA"<<endl;
    archivo3<<"                                 REPORTE DE CALIFICACIONES"<<endl;
    archivo3<<endl;
    archivo3<<"Búsqueda de calificaciones "<<endl;
    archivo3<<"\nALGORITMO: ";
    if(menu==1)
    {
        archivo3<<"Lineal "<<endl;
        archivo3<<"\nLa calificación a buscar fue de: "<<notas_buscar<<endl;
        bool c;
        c=false;
        string aux;
        for(int i=1; i<=n; i++)
        {
            if(notas[i]==notas_buscar)
            {
                c=true;
                aux=nombres[i];

            }

        }
        if(c==true)
        {
            for(int i=0; i<n; i++)

            {
                archivo3<<"\nCorresponde al estudiante: "<<aux<<endl;
                break;
            }
        }
        else
        {
            archivo3<<"\nLa calificación ingresada no corresponde a ningún estudiante"<<endl;
        }

    }
    else if(menu==2)
    {
        archivo3<<"Binaria "<<endl;
        archivo3<<"\nLa calificación a buscar fue de: "<<notas_buscar<<endl;
        bool c=false;
        int mitad, inferior, superior;
        inferior=0;
        superior=n-1;
        while(inferior<=superior)
        {
            mitad=(superior+inferior)/2;
            if(notas[mitad]==notas_buscar)
            {
                c=true;
                aux=nombres[mitad];
                break;
            }
            if(notas[mitad]>notas_buscar)
            {
                superior=mitad-1;
            }
            if(notas[mitad]<notas_buscar)
            {
                inferior=mitad+1;
            }
        }
        if(c==true)
        {
            for(int i=0; i<n; i++)

            {
                archivo3<<"\nCorresponde al estudiante: "<<aux<<endl;
                break;
            }
        }
        else
        {
            archivo3<<"\nLa calificación ingresada no corresponde a ningún estudiante"<<endl;
        }

    }

    else if(menu==3)
    {
        archivo3<<"Interpolación "<<endl;
        archivo3<<"\nLa calificación a buscar fue de: "<<notas_buscar<<endl;
        int primero = 0;
        int ultimo = n-1;
        int medio;
        int cont=0;

        while(notas[primero] != notas_buscar && cont<=ultimo )
        {

            medio = primero + ((notas_buscar - notas[primero])*(ultimo-primero))/(notas[ultimo]-notas[primero]);


            if(notas[medio]<notas_buscar)

                primero = medio +1;

            else if(notas[medio]>notas_buscar)

                ultimo = medio-1;

            else
                primero = medio;

            cont++;

        }
        if(notas[primero]==notas_buscar){
            archivo3<<"\nCorresponde al estudiante: "<<nombres[primero]<<endl;
            }
            else
        {
            archivo3<<"\nLa calificación ingresada no corresponde a ningún estudiante"<<endl;
        }
    }
    archivo3<<endl;
    archivo3<<"                                    _________________________"<<endl;
    archivo3<<"                                          "<<profesor<<endl;
    archivo3<<"                                          "<<cedula;
    archivo3.close();
}

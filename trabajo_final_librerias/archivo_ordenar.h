void archivo_ordenado(int n, double notas[],string profesor,long int cedula,int m)
{

    ofstream archivo2;
    archivo2.open("colegio//ordenamiento.txt",ios::out);
    archivo2<<"                                       COLEGIO MEJIA"<<endl;
    archivo2<<"                                 REPORTE DE CALIFICACIONES"<<endl;
    archivo2<<endl;
    archivo2<<"Calificaciones ordenadas "<<endl;
    archivo2<<endl;
    archivo2<<"Algoritmo: ";
    if(m==1)
    {
        archivo2<<"Burbuja "<<endl;
    }
    if(m==2)
    {
        archivo2<<"Selección "<<endl;
    }
    if(m==3)
    {
        archivo2<<"Merge Sort "<<endl;
    }
    if(m==4)
    {
        archivo2<<"Quick Sort "<<endl;
    }
    if(m==5)
    {
        archivo2<<"Inserción "<<endl;
    }
    if(m==6)
    {

        archivo2<<"Heapsort "<<endl;

    }
    archivo2<<endl;
    archivo2<<"N. ";
    for(int i=1; i<=n; i++)
    {
        archivo2<<"|"<<notas[i]<<"|";
    }
    archivo2<<endl;
    archivo2<<"                                    _________________________"<<endl;
    archivo2<<"                                          "<<profesor<<endl;
    archivo2<<"                                          "<<cedula;

    archivo2.close();
}

void archivo(int n,string nombres[],double notas[],string profesor,string materia,long int cedula)
{
    double promedio;
    ofstream archivo1;
    double suma=0;
    int apro=0,sus=0,repro=0;
    archivo1.open("colegio//calificaciones.txt",ios::out);
    archivo1<<endl;
    archivo1<<"                                       COLEGIO MEJIA"<<endl;
    archivo1<<"                                 REPORTE DE CALIFICACIONES"<<endl;
    archivo1<<endl;
    archivo1<<"Año Lectivo: 2019 - 2020"<<endl;
    archivo1<<"Materia: "<<materia<<endl;
    archivo1<<endl;
    archivo1<<"N.                             Estudiante                      Calificación"<<endl;

    for(int i=1; i<=n; i++)
    {

        suma=suma+notas[i];
        if((notas[i]>=1)&&(notas[i]<9))
        {
            repro ++;
        }
        else if((notas[i]>=9)&&(notas[i]<14))
        {
            sus ++;
        }
        else if((notas[i]>=14)&&(notas[i]<=20))
        {
            apro++;
        }
        archivo1<<i<<"                              "<<nombres[i]<<"                                "<<notas[i];
        archivo1<<endl;
    }
    archivo1<<endl;
    promedio=suma/n;
    archivo1<<"RESUMEN"<<endl;
    archivo1<<endl;
    archivo1<<"Promedio del curso:                 "<<promedio<<endl;
    archivo1<<endl;
    archivo1<<"TOTAL                                   Aprobados (14-20)             "<<apro<<endl;
    archivo1<<"                                        Suspenso (09-13)              "<<sus<<endl;
    archivo1<<"                                        Reprobados (01-08)            "<<repro<<endl;
    archivo1<<endl;
    archivo1<<endl;
    archivo1<<"                                    _________________________"<<endl;
    archivo1<<"                                          "<<profesor<<endl;
    archivo1<<"                                          "<<cedula;

    archivo1.close();
}


void ingresar_estudiantes(int n,string nombres[],double notas[])
{

    for(int i=1; i<=n; i++)
    {
        cin.ignore();
        cout<<"\nIngrese el nombre del estudiante: ";
        getline(cin,nombres[i]);
        do
        {
            cout<<"\nIngrese su calificación: ";
            cin>>notas[i];
        }
        while((notas[i]<1)|(notas[i]>20));
    }

}

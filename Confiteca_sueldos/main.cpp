#include <iostream>
double sueldo (double sueldo_hora);

using namespace std;

int main()
{
    double sueldohora;
    cout << "Ingrese el sueldo del trabajador por hora: " << endl;
    cin>>sueldohora;
    cout<<"El sueldo es: "<<sueldo(sueldohora);

    return 0;
}

double sueldo (double sueldo_hora)
{
    double horas_diarias, s=0,sueldo;

    while (sueldo_hora<=0)
    {
        cout<<"ERROR, INGRESE UN SUELDO ADECUADO: "<<endl;
        cin>>sueldo_hora;
    }
 if (sueldo_hora>0)
    {
    for (int i=1;i<=5;i++)
    {
       cout<<"Ingrese las horas del dia " <<i<<" : ";
       cin>>horas_diarias;

       while (horas_diarias<=0)
        {
        cout<<"EROR: Ingrese las horas del dia " <<i<<" : ";
       cin>>horas_diarias;
        }
          if (horas_diarias>0)
       {
          s=s+horas_diarias;
       }

    }
    sueldo=s*sueldo_hora;

    }
    sueldo=s*sueldo_hora;
     cout<<"El total de horas trabajadas es: "<<s<<endl;
    return sueldo;
}

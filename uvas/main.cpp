#include <iostream>

using namespace std;
int main()
{
    int tama;
    double kilo, ganancia;
    char tipo=' ';

    do
    {

    cout<<"Ingrese el precio inicial del kilo de uvas: ";
    cin>>ganancia;
    cout<<" Ingrese el numero de kilos: ";
    cin>>kilo;
    cout<<"Ingrese el tipo de uva entre tipos a y b: ";
    cin>> tipo;
    cout<<"Ingrese el largo de la uva: ";
    cin>> tama;

    }
    while((((tipo != 'a')&&((tama!=1)||(tama!=2)))&&((tipo != 'b')&&((tama!=1)||(tama!=2))))||(ganancia<0)||(kilo<0));
  if (tipo=='a')
  {
      if(tama==1)
      {
          ganancia=kilo*(ganancia+0.2);
      }
      if(tama==2)
      {
          ganancia=kilo*(ganancia+0.3);
      }
  }
  if(tipo=='b')
  {
      if(tama==1)
      {
          ganancia=kilo*(ganancia-0.3);
      }
      if(tama==2)
      {
          ganancia=kilo*(ganancia-0.5);
      }
  }
  cout<<"La ganancia obtenida es: "<<ganancia;
    return 0;
}

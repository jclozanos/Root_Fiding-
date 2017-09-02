//Este código imprime una tabla que relaciona el número de iteraciones (de distintos métodos para hallar raices) con la diferencia porcentual con el valor real de cada iteración.
#include <iostream>
#include <cmath>

double f(double v) //Definimos la función para el método de bisección
{
  return (pow(v,3)+20*v-7);
}
double g(double w) //Definimos la función para el método de Regula-Falsi
{
  return (atan(w)/exp(w)+3);
}
double h(double x) //Definimos la función para el método de punto fijo
{
  return (exp(-x)); //Se busca la raiz de la función h(x)=exp(-x)-x=0, pero se redefine como h1(x)=exp(-x) para desarrollar el método acorde a la teoría
}
double n(double y) //Definimos la función para el método de la secante
{
  return (log(y)+pow(y,3)-15);
}
double m(double z) //Definimos la función para el método de Newton
{
  return (exp(z)+z-35);
}
double dm(double z) //Definimos la derivada de m=m(z)
{
  return (exp(z)+1);
}
int main(void) 
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  const double eps=(1*pow(10,-9));
  int MAX=35;

  //MÉTODO DE BISECCIÓN

  std::cout<<"\nMétodo de bisección\n\n";
  int ii=1;
  double vl=-1,vu=2,vr=0,vreal=0.347894702611; //El valor real se calcula con aprox 30 iteraciones con el método de Newton 
  while(ii<=MAX)
    {
      vr=0.5*(vl+vu);
      std::cout << ii <<"\t"<<std::fabs(vr-vreal)/vreal*100<< "\n"; //Se imprime el número de iteración, junto con la diferencia de error porcential para el xr de cada iteración
      if(std::fabs(f(vr))<=eps)break;
      if(f(vr)*f(vl)<0)
	vu=vr;
      else
	vl=vr;
      ii++;
    }
  
  //MÉTODO DE REGULA-FALSI

  std::cout<<"\nMétodo de Regula-Falsi\n\n";
  int jj=1;
  double wl=-2,wu=-1,wr=0,wreal=-1.2211779167292903; 
  while(jj<=MAX)
    {
      wr=wu-((g(wu)*(wl-wu))/(g(wl)-g(wu))); //El único cambio con respecto al método de bisección es la definción de xr
      std::cout << jj <<"\t"<<std::fabs((wr-wreal)/wreal)*100<< "\n"; 
      if(std::fabs(g(wr))<=eps)break;
      if(g(wr)*g(wl)<0)
	wu=wr;
      else
	wl=wr;
      jj++;
    }
  
  //Método del punto fijo
  
  std::cout<<"\nMétodo del punto fijo\n\n";
  int kk=1;
  double xr=0, xreal=0.56714329040978384;
  while (kk<=MAX)
    {
      xr=h(xr);
      std::cout<<kk<<"\t"<<std::fabs(xr-xreal)/xreal*100<<"\n";
      if(std::fabs(h(xr)-xr)<eps) break;
      kk++;
    }
  
  //Método de la secante
  
  std::cout<<"\nMétodo de la secante\n\n";
  int ll=1;
  double y0=2,y1=3,temp=0,yreal=2.4168677246904133;
  while(ll<=MAX)
    {
      temp=y1;
      y1=y1-((y1-y0)/(n(y1)-n(y0))*n(y1));
      y0=temp;
      std::cout<<ll<<"\t"<<fabs(y1-yreal)/yreal*100<<"\n";
      if(std::fabs(n(y1))<eps) break;
      ll++;
    }

  //Método de Newton

  std::cout<<"\nMétodo de Newton\n\n";
  int cc=1;
  double z0=3, zreal=3.4515252441068416;
  while (cc<=MAX)
    {
      z0=z0-(m(z0)/dm(z0));
      std::cout<<cc<<"\t"<<fabs(z0-zreal)/zreal*100<<"\n";
      if (std::fabs(m(z0))<eps) break;
      cc++;
    }
  return 0;
}


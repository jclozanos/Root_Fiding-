#include<iostream>
#include<cmath>
double f(double x)
{
  return (exp(-x)-x);
}
int main(void)
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  int NMAX=50,ii=0;
  double xl=12,xu=18,xr=0;
  const double eps=1*pow(10,-9);
  std::cout<<"(Iteración/x up/x low/Valor de la raiz/Imagen de la raiz)\n";
  while(ii<=NMAX)
    {
      xr=xu-((f(xu)*(xl-xu))/(f(xl)-f(xu)));
      std::cout << ii << "\t" << xu << "\t" << xl << "\t" << xr << "\t" << f(xr)<<"\n";
      if(std::fabs(f(xr))<=eps)break;
      if(f(xr)*f(xl)<0)
	xu=xr;
      else
	xl=xr;
      ii++;
    }
  return 0;
}

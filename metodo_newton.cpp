//Este código calcula raices de funciones usando el método de Newton_Raphson
#include<iostream>
#include<cmath>
double f(double x)
{
  return (exp(-x)-x);
}
double df(double x)
{
  return (-exp(-x)-1);
}
int main(void)
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  std::cout<<"(Iteración/Valor de la raiz/Imagen de la raiz)\n";
  int NMAX=50,ii=0;
  double x0=0;
  const double eps=1*(pow(10,-9));
  while (ii<=NMAX)
    {
      std::cout<<ii<<"\t"<<x0<<"\t"<<f(x0)<<"\n";
      x0=x0-(f(x0)/df(x0));
      if(std::fabs(f(x0))<eps) break;
      ii++;
    }
  return 0;
}

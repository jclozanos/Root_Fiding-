//Este método calcula las raices de una función usande el método de la secante
#include <iostream>
#include <cmath>
double f(double x)
{
  return (exp(-x)-x);
}
int main(void)
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  int NMAX=50, ii=0;
  double x0=0,x1=1,temp=0;
  const double eps=1*(pow(10,-9));
  std::cout<<"(Iteración/x0/Imagen de x0/raiz/Imagen de la raiz)\n";
  while (ii<=NMAX)
    {
      temp=x1;
      x1=x1-((x1-x0)/(f(x1)-f(x0))*f(x1));
      x0=temp;
      if(std::fabs(f(x1))<eps) break;
      std::cout<<ii<<"\t"<<x0<<"\t"<<f(x0)<<"\t"<<x1<<"\t"<<f(x1)<<"\n";
      ii++;
    }
  return 0;
}

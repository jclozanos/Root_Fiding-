//Cálculo de raices con el método de punto fijo
#include <iostream>
#include <cmath>
double f(double x)
{
  return (exp(-x));
}
int main(void)
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  int NMAX=50,ii=0;
  double x0=0;
  const double eps=1*(pow(10,-9));
  std::cout<<"(Iteració/Valor de la raiz/Imagen de la raiz)\n";
  while (ii<NMAX)
    {
      std::cout << ii << "\t"<< x0 << "\t" << f(x0)-x0 << "\n";
      x0=f(x0);
      if (std::fabs(f(x0)-x0)<eps) break;
      ii++;
    }
  return 0;
}

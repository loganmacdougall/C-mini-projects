#include<stdio.h>
#include<math.h>

void printResults(double a, double b, double c, double x, double y) {
  printf("\nopposite = %.2lf\nadjacent = %.2lf\nhypotenuse = %.2lf\nx = %.2lf\ny = %.2lf\n\n",a,b,c,x,y);
}

double findOppositePyth(double b, double c, double x, double y) {
   double a = sqrt(c*c - b*b);
  printResults(a,b,c,x,y);
  return a;
}

double findAdjacentPyth(double a, double c, double x, double y) {
  double b = sqrt(c*c - a*a);
  printResults(a,b,c,x,y);
  return b;
}
double findHypotenusePyth(double a, double b, double x, double y) {
  double c = sqrt(a*a + b*b);
  printResults(a,b,c,x,y);
  return c;
}

double findOppositeTrig(double b, double c, double x, double y) {
  double a = sin(x)*c;
  printResults(a,b,c,x,y);
  return a;
}

double findAdjacentTrig(double a, double c, double x, double y) {
  double b = cos(x)*c;
  printResults(a,b,c,x,y);
  return b;
}

double findHypotenuseTrig(double a, double b, double x, double y) {
  double c = b/cos(x);
  printResults(a,b,c,x,y);
  return b;
}
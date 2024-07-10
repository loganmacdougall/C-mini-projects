#include<stdio.h>

void powerRule1(int a, int b) {
  printf("%d\n",a);
}

void powerRule2(int a, int b, int c) {
  printf("%dx + %d\n",a*2,b);
}

void powerRule3(int a, int b, int c, int d) {
  printf("%dx^2 + %dx + %d\n",a*3,b*2,c);
}

void powerRule4(int a, int b, int c, int d, int e) {
  printf("%dx^3 + %dx^2 + %dx + %d\n",a*4,b*3,c*2,d);
}
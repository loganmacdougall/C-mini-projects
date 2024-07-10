#include<stdio.h>

void calculateCoins(int pennies) {
  int dollars = pennies / 100;
  pennies %= 100;
  int quarteres = pennies / 25;
  pennies %= 25;
  int dimes = pennies / 10;
  pennies %= 10;
  int nickels = pennies / 5;
  pennies %= 5;

  printf("%d dollars, %d quarters, %d dimes, %d nickels, %d pennies\n",
  dollars, quarteres, dimes, nickels, pennies);
}
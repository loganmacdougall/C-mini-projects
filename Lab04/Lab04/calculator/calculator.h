#ifndef __CALCULATOR_HEADER
#define __CALCULATOR_HEADER
#define _GNU_SOURCE

#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

double add_calculator(int a, int b);
double sub_calculator(int a, int b);
double mul_calculator(int a, int b);
double div_calculator(int a, int b);
double mod_calculator(int a, int b);

typedef struct _Calculator {
	double (**operations)(int, int);
	int** data;
	int operationCount;
	int dataLength;
} Calculator;

Calculator* create_calculator(double (**operations)(int ,int), int length);
bool load_calculator_data(Calculator* calc, char* filename);
void run_calculator(Calculator* calc);
bool destroy_calculator(Calculator* calc);

#endif

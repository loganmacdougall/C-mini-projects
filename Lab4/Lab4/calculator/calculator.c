#include"calculator.h"

double add_calculator(int a, int b) {return (double)a + (double)b;}
double sub_calculator(int a, int b) {return (double)a - (double)b;}
double mul_calculator(int a, int b) {return (double)a * (double)b;}
double div_calculator(int a, int b) {return (double)a / (double)b;}
double mod_calculator(int a, int b) {return a % b;}


Calculator* create_calculator(double (**operations)(int ,int), int length) {
	Calculator* calc = malloc(sizeof(Calculator));
	calc->operations = operations;
	calc->operationCount = length;

	return calc;
}

bool load_calculator_data(Calculator* calc, char* filename) {
	int dataBufferSize = 100;
	int count = 0;
	calc->data = malloc(dataBufferSize*sizeof(*calc->data));
	
	int op;
	int a;
	int b;

	FILE* in = fopen(filename, "r");
	for(; fscanf(in, "%d %d %d",&op, &a, &b) != EOF; count++) {
		if (count >= dataBufferSize - 1) {
			dataBufferSize+=100;
			calc->data = realloc(calc->data,dataBufferSize*sizeof(*calc->data));
		}

		calc->data[count] = malloc(3 * sizeof(**calc->data));
		calc->data[count][0] = op;
		calc->data[count][1] = a;
		calc->data[count][2] = b;
	}

	calc->dataLength = count; 
	fclose(in);

	return true;
}

void run_calculator(Calculator* calc) {
	int dataLength = calc->dataLength;
	for (int i = 0; i < dataLength; i++) {
		int op = calc->data[i][0];
		int a  = calc->data[i][1];
		int b  = calc->data[i][2];
		printf("%.5lf\n",calc->operations[op](a, b));
	}
}

bool destroy_calculator(Calculator* calc) {
	int numOfData = calc->dataLength;
	for (int i = 0; i < numOfData; i++) {
		free(calc->data[i]);
	}
	free(calc->data);

	free(calc);

	calc = NULL;

	return true;
}


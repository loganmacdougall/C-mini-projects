#include<stdio.h>

int largestProduct() {
	int grid[20][20];
	for (int i = 0; i < 20; i++)
	for (int j = 0; j < 20; j++)
	scanf("%2d", &grid[j][i]);

	int max = 0;

	for (int i = 0; i < 20; i++)
	for (int j = 0; j < 16; j++) {
		int horProduct = grid[j][i] * grid[j+1][i] * grid[j+2][i] * grid[j+3][i];
		int verProduct = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
		max = max < horProduct ? horProduct : max;
		max = max < verProduct ? verProduct : max;
	}

	for (int i = 0; i < 16; i++)
	for (int j = 0; j < 16; j++) {
		int rdigProduct = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
		int ldigProduct = grid[i+3][j] * grid[i+2][j+1] * grid[i+1][j+2] * grid[i][j+3];
		max = max < rdigProduct ? rdigProduct : max;
		max = max < ldigProduct ? ldigProduct : max;
	}	
	return max;
}

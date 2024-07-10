#include<math.h>
#include<stdio.h>
#include"mmath.h"

void pascal(int n) {
	for (int i = 0; i <= n; i++) {
		printf("%ld ",nchoosek(n,i));
	}
	printf("\n");	
}

#include<math.h>
#include<stdio.h>

void primes(long n) {

        long double largestPossibleFactor = sqrt(n);

        for (long i = 2;i <= largestPossibleFactor; i++) {
                while (n % i == 0) {
                        printf("%ld ", i);
                        n /= i;
                        if (n == 1) break;
                }

                if (n == 1) break;
        }

        if (n > 1) printf("%ld ",n);
	printf("\n");
}

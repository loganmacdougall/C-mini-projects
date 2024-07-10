#include<math.h>

long fact(int n) {
        if (n == 0) return 1;
        long product = 1;

        for (int i = 2; i <= n; i++) product *= i;

        return product;
}

long npermk(int n, int k) {
        return fact(n) / fact(n - k);
}

long nchoosek(int n, int k) {
        return npermk(n,k) / fact(k);
}

int prime(long n) {
	long double nsqrt = sqrt(n);
	for (long i = 2; i <= nsqrt; i++) {
		if (n % i == 0) return 0x0;
	}
	return 0x1;
}

int gcd(int n, int m) {
	if (n == m) return n;
	int a = m>n ? m : n;
	int b = m>n ? n : m;
	return gcd(a-b,b);
}

int lcm(int n, int m) {
	int a = n;
	int b = m;
	while(a != b) {
		if (a < b) a+= n;
		else b += m;
	}
}

char bitrevc(char c) {
	char rev = 0x0;
	for (int i = 0; i < 8; i++) {
		if (i != 0) {
			rev <<= 1;
			c >>= 1;
		}
		if (c & 0x1) rev++; 
	}
	return rev;
}

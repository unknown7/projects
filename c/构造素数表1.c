#include <stdio.h>
#include <math.h>
int isPrime(int x);
int main() {
	const int SIZE = 20;
	int primes[SIZE];
	int cnt = 0;
	int number = 1;
	while (cnt < SIZE) {
		if (isPrime(number)) {
			primes[cnt++] = number;
		}
		number++;
	}
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("%d\t", primes[i]);
	}
	return 0;
}
int isPrime(int x) {
	int isPrime = 1;
	if (x == 1 || (x % 2 ==0 && x != 2)) {
		isPrime = 0;
		return isPrime;
	}
	int i;
	for (i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			isPrime = 0;
			break;
		}
	}
	return isPrime;
}

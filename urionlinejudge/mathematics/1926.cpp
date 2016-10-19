#include <bits/stdc++.h>

#define MAX (int) 1e6

using namespace std;

int divisors[MAX + 5], twin_primes[MAX + 5];

bool is_prime(int n) {
	return divisors[n] == 2;
}

int main(void) {
	for(int i = 1; i <= MAX; ++i) {
		for(int j = i; j <= MAX; j += i) {
			if(j % i == 0)
				divisors[j]++;
		}
	}
	for(int i = 2; i <= MAX; ++i) {
		twin_primes[i] = twin_primes[i - 1] + ((is_prime(i) and is_prime(i - 2)) | (is_prime(i) and is_prime(i + 2)));
	}

	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", twin_primes[max(x, y)] - twin_primes[min(x, y) - 1]);
	}
	return 0;
}

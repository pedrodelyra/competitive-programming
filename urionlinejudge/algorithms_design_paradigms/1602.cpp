#include <bits/stdc++.h>

#define MAX (int) 2e6

using namespace std;

int divisors[MAX + 5], hyperprime[MAX + 5], sum[MAX + 5];

inline bool is_prime(int n) {
	return divisors[n] == 2;
}

int main(void) {
	for(int i = 1; i <= MAX; ++i) {
		for(int j = i; j <= MAX; j += i) {
			divisors[j]++;
		}
	}

	for(int i = 1; i <= MAX; ++i) {
		if(is_prime(divisors[i]))
			hyperprime[i] = true;
	}

	for(int i = 1; i <= MAX; ++i) {
		sum[i] = sum[i - 1] + hyperprime[i];
	}

	int n;
	while(~scanf("%d", &n)) {
		printf("%d\n", sum[n]);
	}

	return 0;
}

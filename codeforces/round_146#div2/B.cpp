#include <bits/stdc++.h>

#define MAX (int) 1e6 + 5
#define MOD 1073741824

using namespace std;

int divisors[MAX];

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int n = a * b * c;
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; j += i) {
			divisors[j]++;
		}
	}
	int sum = 0;
	for(int i = 1; i <= a; ++i) {
		for(int j = 1; j <= b; ++j) {
			for(int k = 1; k <= c; ++k) {
				sum = (sum + divisors[i * j * k]) % MOD;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}

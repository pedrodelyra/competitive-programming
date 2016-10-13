#include <bits/stdc++.h>

#define MAX 1000005

using namespace std;

long long divine_num[MAX], divisors_sum[MAX];

int main(void) {
	for(int i = 1; i <= MAX; ++i) {
		for(int j = i; j <= MAX; j += i) {
			divisors_sum[j] += i;
		}
	}

	for(int i = 1; i <= MAX; ++i) {
		divine_num[i] = divine_num[i - 1] + divisors_sum[i];
	}

	int n;
	while(scanf("%d", &n), n) {
		printf("%lld\n", divine_num[n]);
	}
	return 0;
}

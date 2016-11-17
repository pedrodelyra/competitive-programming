#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
	int divisors = 0;
	for(int i = 2; i * (long long) i <= n; ++i) {
		if(n % i == 0) ++divisors;
	}
	return divisors == 0;
}

int main(void) {
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = n; !ans and i >= 2; --i) {
		if(is_prime(i)) {
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}

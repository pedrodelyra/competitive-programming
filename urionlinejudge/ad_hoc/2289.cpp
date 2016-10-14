#include <bits/stdc++.h>

using ull = unsigned long long int;

int main(void) {
	ull x, y;
	while(scanf("%llu %llu", &x, &y), x | y) {
		ull z = x ^ y;
		int count = 0;
		while(z) {
			++count;
			z = z & (z - 1);
		}
		printf("%d\n", count);
	}
	return 0;
}

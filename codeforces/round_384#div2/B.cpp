#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

int main(void) {
	lld n, k;
	scanf("%lld %lld", &n, &k);
	lld count = 1;
	while(k % 2 == 0) {
		k >>= 1;
		++count;
	}
	printf("%lld\n", count);
	return 0;
}

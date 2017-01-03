#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

lld gcd(lld a, lld b) {
	return a == 0 ? b : gcd(b % a, a);
}

lld lcm(lld a, lld b) {
	return a * b / gcd(a, b);
}

lld lcm(lld a, lld b, lld c) {
	return lcm(a, lcm(b, c));
}

int main(void) {
	int n;
	scanf("%d", &n);
	lld ans = 0, m = min(n - 1, 10);
	for(int i = 0; i <= m; ++i) {
		for(int j = 0; j <= m; ++j) {
			for(int k = 0; k <= m; ++k) {
				ans = max(ans, lcm(n - i, n - j, n - k));
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

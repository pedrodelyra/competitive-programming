#include <bits/stdc++.h>

using ll = long long int;

int main(void) {
	ll r, g, b;
	scanf("%llx %llx %llx", &r, &g, &b);
	ll x = (r / g) * (r / g);
	ll y = (g / b) * (g / b) * x;
	printf("%llx\n", x + y + 1);
	return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

class triangle {
private:
	ll a, b, c;

public:
	triangle(ll av, ll bv, ll cv) : a(av), b(bv), c(cv) {}

	const char* category() const {
		if(a + b > c && a + c > b && b + c > a) {
			if(a == b && b == c) return "Equilateral";

			if(a == b || a == c || b == c) return "Isosceles";

			return "Scalene";
		} else {
			return "Invalid";
		}
	}
};

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);

		triangle t(a, b, c);
		printf("Case %d: %s\n", tc, t.category());
	}

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		double r, d, h1;
		scanf("%lf %lf %lf", &r, &d, &h1);
		double alpha = asin((r - h1) / r), beta = asin((r - d) / r);
		double theta = alpha - beta, x = sqrt(r * r - (r - d) * (r - d));
		double h2 = 2 * x * sin(theta) + h1;
		printf("Case %d: %.4lf\n", tc, h2);
	}
	return 0;
}

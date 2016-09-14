#include <bits/stdc++.h>

#define EPS 1e-7

int p, q, r, s, t, u;

double f(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * (x * x) + u;
}

int main(void) {
	while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
		double low = 0.0, high = 1.0, sol = DBL_MAX;
		if(f(low) * f(high) <= 0.0) {
			while(low + EPS < high) {
				double x = (low + high) / 2.0;
				double result = f(x);
				if(f(low) * f(x) <= 0.0) {
					high = x;
				} else {
					low = x;
				}
			}

			sol = (low + high) / 2.0;
		}

		printf(sol < DBL_MAX ? "%.4lf\n" : "No solution\n", sol);
	}

	return 0;
}

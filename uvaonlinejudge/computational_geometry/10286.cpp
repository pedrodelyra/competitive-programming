#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

int main(void) {
	double L;
	while(~scanf("%lf", &L)) {
		double alpha = 2 * pi / 5, beta = (alpha - (pi / 2)) / 2, gamma = pi - alpha - beta;
		printf("%.10lf\n", L * sin(alpha) / sin(gamma));
	}
	return 0;
}

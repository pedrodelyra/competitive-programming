#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;

bool equals(double x, double y) { return fabs(x - y) < eps; }

int main(void) {
	double ma, mb, mc;
	while(~scanf("%lf %lf %lf", &ma, &mb, &mc)) {
		double s = (ma + mb + mc) / 2;
		double a = 4 * sqrt(s * (s - ma) * (s - mb) * (s - mc)) / 3;
		printf("%.3lf\n", a != a || equals(a, 0) ? -1.0 : a);
	}
	return 0;
}

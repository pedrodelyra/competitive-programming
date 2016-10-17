#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

bool equals(double x, double y) { return fabs(x - y) < eps; }

int main(void) {
	int n;
	scanf("%d", &n);
	while(n) {
		double ha, hb, hc;
		scanf("%lf %lf %lf", &ha, &hb, &hc);
		double h = (1 / ha + 1 / hb + 1 / hc) / 2;
		double a = 1 / (4 * sqrt(h * (h - 1 / ha) * (h - 1 / hb) * (h - 1 / hc)));
		if(a != a || equals(a, 0)) {
			printf("These are invalid inputs!\n");
			--n;
		} else {
			printf("%.3lf\n", a);
		}
	}
	return 0;
}

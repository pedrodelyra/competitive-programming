#include <bits/stdc++.h>

using namespace std;
using roots = pair<double, double>;

roots bhaskara(double a, double b, double c) {
	double delta = b * b - 4 * a * c;
	double x1 = (-b - sqrt(delta)) / (2 * a), x2 = (-b + sqrt(delta)) / (2 * a);
	return roots(x1, x2);
}

double box_volume(double l, double w, double x) {
	return (w - 2 * x) * (l - 2 * x) * x;
}

int main(void) {
	double l, w, x1, x2;
	while(~scanf("%lf %lf", &l, &w)) {
		tie(x1, x2) = bhaskara(12, -4 * (w + l), w * l);
		auto x_max  = box_volume(l, w, x1) > box_volume(l, w, x2) ? x1 : x2, x_min = min(l, w) / 2;
		printf("%.3lf %.3lf %.3lf\n", x_max, 0.0, x_min);
	}
	return 0;
}

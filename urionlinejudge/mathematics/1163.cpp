#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9, pi = 3.14159, g = 9.80665;

int main(void) {
	double h, p1, p2;
	while(~scanf("%lf %lf %lf", &h, &p1, &p2)) {
		int n;
		scanf("%d", &n);
		while(n--) {
			double alpha, v;
			scanf("%lf %lf", &alpha, &v);
			double Voy = v * sin(alpha * pi / 180), Vox = v * cos(alpha * pi / 180);
			double t = (Voy + sqrt(Voy * Voy + 2 * g * h)) / g, x = Vox * t;
			printf("%.5lf -> %s\n", x, p1 < x + eps and x + eps < p2 ? "DUCK" : "NUCK");
		}
	}
	return 0;
}

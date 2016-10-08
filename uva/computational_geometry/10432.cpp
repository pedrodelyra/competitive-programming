#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

int main(void) {
	double r; int n;
	while(~scanf("%lf %d", &r, &n)) {
		double theta = 2 * pi / n, chord = 2 * r * sin(theta / 2);
		double s = r + chord / 2, pizza_slice_without_border = sqrt(s * (s - r) * (s - r) * (s - chord));
		printf("%.3lf\n", n * pizza_slice_without_border);
	}
	return 0;
}

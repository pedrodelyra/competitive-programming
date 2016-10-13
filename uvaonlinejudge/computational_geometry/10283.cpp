#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

int main(void) {
	int R, n;
	while(~scanf("%d %d", &R, &n)) {
		if(n == 1) {
			printf("%.10lf %.10lf %.10lf\n", (double) R, 0, 0);
		} else {
			double r = R * sin(pi / n) / (1 + sin(pi / n));
			double theta = pi * (n - 2) / n, sectors_sum = n * theta / 2 * r * r, polygon_area = n * ((R - r) * cos(pi / n) * r);
			double blue_area = polygon_area - sectors_sum, green_area = pi * (R * R - n * r * r) - blue_area;
			printf("%.10lf %.10lf %.10lf\n", r, blue_area, green_area);
		}
	}
	return 0;
}

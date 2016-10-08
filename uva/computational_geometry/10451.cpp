#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

int main(void) {
	int n, tc = 0; double area;
	while(scanf("%d %lf", &n, &area), n >= 3) {
		double inradius = sqrt(area / (n * tan(pi / n))), circumradius = inradius / cos(pi / n);
		printf("Case %d: %.5lf %.5lf\n", ++tc, circumradius * circumradius * (pi - n * sin(2 * pi / n) / 2), area - pi * inradius * inradius);
	}
	return 0;
}

#include <bits/stdc++.h>

#define EPS 1e-12

using namespace std;

int main(void) {
	double l, w, h, theta, pi = acos(-1.0);
	while(~scanf("%lf %lf %lf %lf", &l, &w, &h, &theta)) {
		theta = pi * theta / 180.0;
		if(theta < atan2(h, l) + EPS) {
			printf("%.3lf mL\n", ((h * l) - ((l * l * tan(theta) / 2))) * w);
		} else {
			printf("%.3lf mL\n", w * h * h * tan(pi / 2 - theta) / 2);
		}
	}
	return 0;
}

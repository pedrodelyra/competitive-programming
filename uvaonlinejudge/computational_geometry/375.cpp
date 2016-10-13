#include <bits/stdc++.h>

#define EPS 1e-6

using namespace std;

const double pi = acos(-1.0);

double sum(double height, double radius) {
	if(radius < EPS) {
		return 0;
	} else {
		double new_height = height - 2 * radius, new_radius = radius * new_height / height;
		return sum(new_height, new_radius) + 2 * pi * radius;
	}
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		double base, height;
		scanf("%lf %lf", &base, &height);

		double triangle_area = (base * height) / 2;
		double triangle_perimeter = 2 * hypot(base / 2, height) + base;
		double incircle_radius = 2 * triangle_area / triangle_perimeter;
		printf("%13.6lf\n", sum(height, incircle_radius));
		if(tc) printf("\n");
	}
	return 0;
}

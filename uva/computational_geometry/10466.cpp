#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793

class Point {
public:
	double x;
	double y;

	Point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

	double distance() {
		return hypot(x, y);
	}
};

int main(void) {
	int n, T;
	while(scanf("%d %d", &n, &T) != EOF) {
		Point last_planet;
		for(int i = 0; i < n; ++i) {
			int r, t;
			scanf("%d %d", &r, &t);
			double theta = 2 * PI * T / (double) t;
			Point current_planet(r * cos(theta) + last_planet.x, r * sin(theta) + last_planet.y);
			if(i) printf(" ");
			printf("%.4lf", current_planet.distance());
			last_planet = current_planet;
		}
		printf("\n");
	}

	return 0;
}

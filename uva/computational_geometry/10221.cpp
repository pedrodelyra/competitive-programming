#include <bits/stdc++.h>

#define EPS 1e-12

using namespace std;

const double pi = acos(-1.0), earth_radius = 6440;

double deg_to_rad(double theta) { return pi * theta / 180; }

double min_to_rad(double theta) { return deg_to_rad(theta / 60); }

map<string, double (*)(double)> rad_from = {{"deg", deg_to_rad}, {"min", min_to_rad}};

int main(void) {
	int dist, angle;
	while(~scanf("%d %d", &dist, &angle)) {
		char angle_unit[5];
		scanf(" %s", angle_unit);

		double radius = dist + earth_radius, theta = rad_from[angle_unit](angle);

		if(theta > pi + EPS) theta = 2 * pi - theta;

		printf("%lf %lf\n", radius * theta, 2 * radius * sin(theta / 2));
	}
	return 0;
}

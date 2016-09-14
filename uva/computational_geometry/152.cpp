#include <bits/stdc++.h>

#define EPS 1e-4

using namespace std;

class point {
public:
	double x, y, z;

	point(double xv, double yv, double zv) : x(xv), y(yv), z(zv) {}

	double distance(point& other) {
		return hypot(hypot(x - other.x, y - other.y), z - other.z);
	}
};

vector<point> points;
int counter[10];

int main(void) {
	int x, y, z;
	while(scanf("%d %d %d", &x, &y, &z), x | y | z) {
		points.push_back(point(x, y, z));
	}

	int n = points.size();
	for(int i = 0; i < n; ++i) {
		double min_dist = DBL_MAX;
		for(int j = 0; j < n; ++j) {
			if(i == j) continue;
			min_dist = min(min_dist, points[i].distance(points[j]));
		}

		if(min_dist < 10.0 - EPS) counter[(int) min_dist]++;
	} 

	for(int i = 0; i < 10; ++i) {
		printf("%4d", counter[i]);
	}
	printf("\n");

	return 0;
}

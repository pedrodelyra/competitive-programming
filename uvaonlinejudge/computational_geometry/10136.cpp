#include <bits/stdc++.h>

#define EPS 1e-8

using namespace std;

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

	double distance(const point& p) {
		return hypot(x - p.x, y - p.y);
	}
};

class circle {
private:
	point  center;
	double radius;

public:
	circle(const point& p, const point& q, const double r) {
		double d2 = (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
		double det = r * r / d2 - 0.25;

		if(det + EPS > 0) {
			double h = sqrt(det);

			auto x = (p.x + q.x) * 0.5 + (p.y - q.y) * h;
			auto y = (p.y + q.y) * 0.5 + (q.x - p.x) * h;

			center = point(x, y), radius = r;
		} else {
			radius = 0;
		}
	}

	bool contains(const point& p) {
		return center.distance(p) < radius + EPS;
	}
};

int main(void) {
	int tests;
	scanf("%d\n\n", &tests);
	for(int tc = 0; tc < tests; ++tc) {
		char input[128];
		vector<point> points;
		while(gets(input) and *input) {
			double x, y;
			sscanf(input, "%lf %lf", &x, &y);
			points.push_back(point(x, y));
		}

		int n = points.size(), max_chips = 1;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i == j) continue;

				circle cookie(points[i], points[j], 2.5);
				for(int k = 0, count = 0; k < n; ++k) {
					if(cookie.contains(points[k])) {
						max_chips = max(max_chips, ++count);
					}
				}
			}
		}
		if(tc) printf("\n");
		printf("%d\n", max_chips);
	}
	return 0;
}

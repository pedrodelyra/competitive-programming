#include <bits/stdc++.h>

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
	circle(const point& p, const double r) : center(p), radius(r) {}

	bool contains(const point& p) {
		return center.distance(p) <= radius;
	}
};

int main(void) {
	int n, l;
	while(scanf("%d %d", &n, &l), n | l) {
		vector<circle> circles = {circle(point(0, 0), l), circle(point(0, l), l),
					  circle(point(l, 0), l), circle(point(l, l), l)};
		int m = 0;
		for(int i = 1; i <= n; ++i) {
			double x, y;
			scanf("%lf %lf", &x, &y);
			point p(x, y);
			bool is_within = true;
			for(auto& c : circles) {
				is_within = is_within and c.contains(p);
			}
			if(is_within) ++m;
		}
		printf("%.5lf\n", l * l * m / (double) n);
	}
	return 0;
}

#include <bits/stdc++.h>

#define oo 1e12

using namespace std;

const double pi = acos(-1.0);

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

	void rotate(const double theta) {
		auto new_x = cos(theta) * x - sin(theta) * y;
		auto new_y = sin(theta) * x + cos(theta) * y;
		x = new_x, y = new_y;
	}
};

class triangle {
private:
	point a, b, c;

public:
	triangle(const point& p, const point& q, const point& r) : a(p), b(q), c(r) {}

	point circumcenter() const {
		auto d = 2 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));

		auto a2 = a.x * a.x + a.y * a.y;
		auto b2 = b.x * b.x + b.y * b.y;
		auto c2 = c.x * c.x + c.y * c.y;

		auto x = (a2 * (b.y - c.y) + b2 * (c.y - a.y) + c2 * (a.y - b.y)) / d;
		auto y = (a2 * (c.x - b.x) + b2 * (a.x - c.x) + c2 * (b.x - a.x)) / d;

		return point(x, y);
	}
};

int main(void) {
	int n, tc = 0;
	while(scanf("%d", &n), n) {
		double x1, y1, x2, y2, x3, y3, theta = 2 * pi / n;
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

		triangle t(point(x1, y1), point(x2, y2), point(x3, y3));
		point circumcenter = t.circumcenter(), current_point(x1 - circumcenter.x, y1 - circumcenter.y);
		double min_x = oo, max_x = -oo, min_y = oo, max_y = -oo;
		for(int i = 1; i <= n; ++i) {
			min_x = min(min_x, current_point.x), max_x = max(max_x, current_point.x);
			min_y = min(min_y, current_point.y), max_y = max(max_y, current_point.y);
			current_point.rotate(theta);
		}
		printf("Polygon %d: %.3lf\n", ++tc, (max_x - min_x) * (max_y - min_y));
	}

	return 0;
}

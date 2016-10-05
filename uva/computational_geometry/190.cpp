#include <bits/stdc++.h>

#define EPS 1e-12

using namespace std;

bool equals(double x, double y) { return fabs(x - y) < EPS; }

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

	double distance(const point& p) {
		return hypot(x - p.x, y - p.y);
	}
};

class circle {
public:
	point center;
	double radius;

	circle(const point& p, const point& q, const point& r) {
		auto a = 2 * (q.x - p.x);
		auto b = 2 * (q.y - p.y);
		auto c = 2 * (r.x - p.x);
		auto d = 2 * (r.y - p.y);

		auto det = a * d - b * c;

		auto k1 = (q.x * q.x + q.y * q.y) - (p.x * p.x + p.y * p.y);
		auto k2 = (r.x * r.x + r.y * r.y) - (p.x * p.x + p.y * p.y);

		auto cx = (k1 * d - k2 * b) / det;
		auto cy = (a * k2 - c * k1) / det;

		center = point(cx, cy);
		radius = center.distance(p);
	}
};

int main(void) {
	double x1, y1, x2, y2, x3, y3;
	while(~scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3)) {
		circle c(point(x1, y1), point(x2, y2), point(x3, y3));
		point center = c.center;
		if(equals(center.x, 0)) {
			printf("x^2 + ");
		} else {
			printf("(x %c %.3lf)^2 + ", center.x < -EPS ? '+' : '-', fabs(center.x));
		}

		if(equals(center.y, 0)) {
			printf("y^2 = %.3lf^2\n", c.radius);
		} else {
			printf("(y %c %.3lf)^2 = %.3lf^2\n", center.y < -EPS ? '+' : '-', fabs(center.y), c.radius);
		}

		printf("x^2 + y^2");
		if(not equals(center.x, 0)) printf(" %c %.3lfx", center.x < -EPS ? '+' : '-', 2 * fabs(center.x));
		if(not equals(center.y, 0)) printf(" %c %.3lfy", center.y < -EPS ? '+' : '-', 2 * fabs(center.y));

		auto k = center.x * center.x + center.y * center.y - c.radius * c.radius;
		printf(" %c %.3lf = 0\n\n", k > EPS ? '+' : '-', fabs(k));
	}
	return 0;
}

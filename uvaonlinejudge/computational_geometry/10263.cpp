#include <bits/stdc++.h>

#define EPS 1e-6

using namespace std;

bool equals(double a, double b) { return fabs(a - b) < EPS; }

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

	double dist(const point& p) {
		return hypot(x - p.x, y - p.y);
	}
};

double det(const point& a, const point& b, const point& c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

class line {
public:
	double a, b, c;

	line(const point& p, const point& q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = p.x * q.y - p.y * q.x;

		auto k = a ? a : b;

		a /= k, b /= k, c /= k;
	}

	point closest(const point& p) {
		auto den = a * a + b * b;
		auto x = (b * (b * p.x - a * p.y) - a * c) / den;
		auto y = (a * (a * p.y - b * p.x) - b * c) / den;

		return point(x, y);
	}
};

class segment {
public:
	point a, b;

	segment(const point& av, const point& bv) : a(av), b(bv) {}

	bool contains(const point& p) const {
		if(equals(a.x, b.x)) {
			return min(a.y, b.y) <= p.y and p.y <= max(a.y, b.y);
		} else {
			return min(a.x, b.x) <= p.x and p.x <= max(a.x, b.x);
		}
	}

	point closest(point& p) {
		line r(a, b);

		auto q = r.closest(p);

		if(equals(det(a, b, q), 0) && this->contains(q)) return q;

		auto dist_a = p.dist(a);
		auto dist_b = p.dist(b);

		return dist_a < dist_b ? a : b;
	}
};

int main(void) {
	double x, y;
	while(scanf("%lf %lf", &x, &y) != EOF) {
		point source(x, y), ans;

		int n;
		scanf("%d", &n);
		
		double x1, y1;
		scanf("%lf %lf", &x1, &y1);

		double min_dist = DBL_MAX;
		for(int i = 0; i < n; ++i) {
			double x2, y2;
			scanf("%lf %lf", &x2, &y2);
			segment s(point(x1, y1), point(x2, y2));

			point closest_point = s.closest(source);
			double current_dist = closest_point.dist(source);

			if(current_dist < min_dist) {
				min_dist = current_dist;
				ans = closest_point;
			}

			x1 = x2, y1 = y2;
		}

		printf("%.4lf\n%.4lf\n", ans.x, ans.y);
	}

	return 0;
}

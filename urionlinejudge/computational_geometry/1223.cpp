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

	segment(const point& av = 0, const point& bv = 0) : a(av), b(bv) {}

	bool contains(const point& p) const {
		if(equals(a.x, b.x)) {
			return min(a.y, b.y) <= p.y and p.y <= max(a.y, b.y);
		} else {
			return min(a.x, b.x) <= p.x and p.x <= max(a.x, b.x);
		}
	}

	double distance(point& p) {
		line r(a, b);

		auto q = r.closest(p);

		if(equals(det(a, b, q), 0) && this->contains(q)) return p.dist(q);

		return min(p.dist(a), p.dist(b));
	}
};

int main(void) {
	int n;
	while(~scanf("%d", &n)) {
		int L, R;
		scanf("%d %d", &L, &R);

		vector<segment> segments(n + 1);
		for(int i = 1; i <= n; ++i) {
			int yi, xf, yf;
			scanf("%d %d %d", &yi, &xf, &yf);
			segments[i] = segment(point(i & 1 ? 0 : L, yi), point(xf, yf));
		}

		double min_radius = DBL_MAX;
		for(int i = 1; i < n; ++i) {
			min_radius = min(min_radius, min(segments[i + 1].distance(segments[i].b), fabs(segments[i].b.x - (i & 1 ? L : 0))));
		}
		min_radius = min(min_radius, fabs(segments[n].b.x - (n & 1 ? L : 0)));

		printf("%.2lf\n", min_radius);
	}

	return 0;
}

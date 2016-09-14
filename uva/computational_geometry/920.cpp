#include <bits/stdc++.h>

#define EPS 1e-6

using namespace std;

bool equals(double x, double y) { return fabs(x - y) < EPS; }

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

	bool operator<(const point& p) {
		return this->x > p.x + EPS;
	}
};

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

	bool operator==(const line& r) const {
		return equals(a, r.a) && equals(b, r.b) && equals(c, r.c);
	}

};

point intersections(const line& r, const line& s) {
	auto det = r.a * s.b - r.b * s.a;

	double x = (-r.c * s.b + r.b * s.c) / det;
	double y = (-s.c * r.a + r.c * s.a) / det;
	return point(x, y);
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n;
		scanf("%d", &n);
		vector<point> points(n);
		for(int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			points[i] = point(x, y);
		}

		sort(points.begin(), points.end());

		double current_height = 0, ans = 0;
		for(int i = 1; i < n; ++i) {
			if(points[i].y > current_height) {
				line r(points[i], points[i - 1]), s(point(-1, current_height), point(0, current_height));
				auto intersection = intersections(r, s);
				double dx = points[i].x - intersection.x, dy = points[i].y - intersection.y;
				ans += hypot(dx, dy);
				current_height = points[i].y;
			}
		}

		printf("%.2lf\n", ans);
	}

	return 0;
}

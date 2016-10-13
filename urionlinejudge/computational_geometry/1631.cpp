#include <bits/stdc++.h>

#define EPS 1e-6

using namespace std;

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}
};

double equals(double x, double y) {
	return fabs(x - y) < EPS;
}

double det(const point& p, const point& q, const point& r) {
	return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
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

	double distance(const point& p) {
		return fabs(a * p.x + b * p.y + c) / hypot(a, b);
	}
};

int main(void) {
	int n;
	while(scanf("%d", &n), n) {
		point points[128];
		for(int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			points[i] = point(x, y);
		}

		double ans = DBL_MAX;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i == j) continue;

				line ln(points[i], points[j]);
				double left_sum = 0, right_sum = 0;
				for(int k = 0; k < n; ++k) {
					if(i == k || j == k) continue;

					double d = det(points[i], points[j], points[k]);
					if(not equals(d, 0)) {
						if(d > EPS) {
							left_sum += ln.distance(points[k]);
						} else {
							right_sum += ln.distance(points[k]);
						}
					}
				}

				ans = min(ans, fabs(left_sum - right_sum));
			}
		}

		printf("%.3lf\n", ans);
	}

	return 0;
}

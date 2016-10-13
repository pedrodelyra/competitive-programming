#include <bits/stdc++.h>

#define EPS 1e-12
#define oo  1e18

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
public:
	point center;
	double radius;

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
	int n;
	while(scanf("%d", &n), n) {
		vector<point> points(n + 1);
		for(int i = 1; i <= n; ++i) {
			double x, y;
			scanf("%lf %lf", &x, &y);
			points[i] = point(x, y);
		}

		double radius;
		scanf("%lf", &radius);

		bool possible = (n == 1) or (n == 2 and points[1].distance(points[2]) < 2 * radius + EPS);
		for(int i = 1; not possible and i < n; ++i) {
			for(int j = 1; not possible and j <= n; ++j) {
				if(i == j) continue;

				circle c(points[i], points[j], radius);
				int count = 0;
				for(int u = 1; u <= n; ++u) {
					if(c.contains(points[u])) ++count;
				}
				if(count == n) possible = true;
			}
		}
		printf(possible ? "The polygon can be packed in the circle.\n" : "There is no way of packing that polygon.\n");
	}
	return 0;
}

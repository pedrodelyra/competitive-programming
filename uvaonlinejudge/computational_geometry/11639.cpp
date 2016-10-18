#include <bits/stdc++.h>

using namespace std;

class point {
public:
	int x, y;

	point(int xv = 0, int yv = 0) : x(xv), y(yv) {}

	bool operator==(const point& p) const {
		return x == p.x and y == p.y;
	}
};

class rectangle {
public:
	point p, q;

	rectangle(const point& pv, const point& qv) : p(pv), q(qv) {}

	int area() const {
		return abs(p.x - q.x) * abs(p.y - q.y);
	}

	rectangle intersection(const rectangle& r) const {
		auto ax = max(p.x, r.p.x);
		auto bx = min(q.x, r.q.x);

		auto ay = max(p.y, r.p.y);
		auto by = min(q.y, r.q.y);

		if(ax < bx and ay < by) {
			return rectangle(point(ax, ay), point(bx, by));
		} else {
			return rectangle(point(), point());
		}
	}
};

int main(void) {
	int tests, total_area = 10000;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		int x1, y1, x2, y2, x3, y3, x4, y4;
		scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		rectangle r1(point(x1, y1), point(x2, y2)), r2(point(x3, y3), point(x4, y4)), intersection = r1.intersection(r2);
		int strongly_area = intersection.area();
		int weakly_area = r1.area() + r2.area() - 2 * strongly_area;
		printf("Night %d: %d %d %d\n", tc, strongly_area, weakly_area, total_area - weakly_area - strongly_area);
	}
	return 0;
}

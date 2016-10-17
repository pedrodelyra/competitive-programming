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

	bool is_degenerated() const {
		return p == q;
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
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int x1, y1, x2, y2, x3, y3, x4, y4;
		scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		rectangle r1(point(x1, y1), point(x2, y2)), r2(point(x3, y3), point(x4, y4));
		rectangle intersection = r1.intersection(r2);
		if(intersection.is_degenerated()) {
			printf("No Overlap\n");
		} else {
			auto p = intersection.p, q = intersection.q;
			printf("%d %d %d %d\n", p.x, p.y, q.x, q.y);
		}
		if(tc) printf("\n");
	}
	return 0;
}

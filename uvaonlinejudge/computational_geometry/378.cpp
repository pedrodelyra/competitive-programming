#include <bits/stdc++.h>

#define INF -1
#define EPS 1e-6

using namespace std;

bool equals(double x, double y) {
	return fabs(x - y) < EPS;
}

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}
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

pair<int, point> intersections(const line& r, const line& s) {
	auto det = r.a * s.b - r.b * s.a;

	if(equals(det, 0)) {
		auto coincident = (r == s) ? INF : 0;
		return { coincident, point() };
	} else {
		double x = (-r.c * s.b + r.b * s.c) / det;
		double y = (-s.c * r.a + r.c * s.a) / det;
		return { 1, point(x, y) };
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("INTERSECTING LINES OUTPUT\n");
	while(n--) {
		int x1, y1, x2, y2, x3, y3, x4, y4;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d %d %d %d", &x3, &y3, &x4, &y4);

		line r(point(x1, y1), point(x2, y2)), s(point(x3, y3), point(x4, y4));
		auto ans = intersections(r, s);
		if(ans.first == 1) {
			point intersection = ans.second;
			printf("POINT %.2lf %.2lf\n", intersection.x, intersection.y);
		} else {
			printf(!~ans.first ? "LINE\n" : "NONE\n");
		}
	}
	printf("END OF OUTPUT\n");

	return 0;
}

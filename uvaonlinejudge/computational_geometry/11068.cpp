#include <bits/stdc++.h>

#define EPS 1e-6

using namespace std;

bool equals(double x, double y) { return fabs(x - y) < EPS; }

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}
};

class line {
public:
	double a, b, c;

	line(double av, double bv, double cv) : a(av), b(bv), c(cv) {}
};

pair<int, point> intersections(const line& r, const line& s) {
	auto det = r.a * s.b - r.b * s.a;

	if(equals(det, 0)) {
		return { 0, point() };
	} else {
		double x = (-r.c * s.b + r.b * s.c) / det;
		double y = (-s.c * r.a + r.c * s.a) / det;
		x = equals(x, 0) ? 0 : x;
		y = equals(y, 0) ? 0 : y;
		return { 1, point(x, y) };
	}
}

int main(void) {
	int a1, b1, c1, a2, b2, c2;
	while(scanf("%d %d %d %d %d %d", &a1, &b1, &c1, &a2, &b2, &c2), a1 | b1 | c1 | a2 | b2 | c2) {
		line ln1(a1, b1, -c1), ln2(a2, b2, -c2);
		auto ans = intersections(ln1, ln2);
		if(ans.first) {
			point intersection(ans.second);
			printf("The fixed point is at %.2lf %.2lf.\n", intersection.x, intersection.y);
		} else {
			printf("No fixed point exists.\n");
		}
	}

	return 0;
}

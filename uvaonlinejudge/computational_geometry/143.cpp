#include <bits/stdc++.h>

#define EPS 1e-9

using namespace std;

bool equals(double x, double y) { return fabs(x - y) < EPS; }

class point {
public:
	double x, y;

	point(double xv, double yv) : x(xv), y(yv) {}
};

double det(const point& P, const point& Q, const point& R) {
	return (Q.x - P.x) * (R.y - P.y) - (Q.y - P.y) * (R.x - P.x);
}

class segment {
public:
	point a, b;

	segment(const point& av, const point& bv) : a(av), b(bv) {}

	bool contains(const point& p) const {
		if(not equals(det(a, b, p), 0)) return false;

		if(equals(a.x, b.x)) {
			return min(a.y, b.y) <= p.y and p.y <= max(a.y, b.y);
		} else {
			return min(a.x, b.x) <= p.x and p.x <= max(a.x, b.x);
		}
	}
};

int main(void) {
	double ax, ay, bx, by, cx, cy;
	while(scanf("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy)) {
		if(equals(ax, 0) && equals(ay, 0) && equals(bx, 0) && equals(by, 0) && equals(cx, 0) && equals(cy, 0)) break;

		point A(ax, ay), B(bx, by), C(cx, cy);
		int count = 0, collinear = equals(det(A, B, C), 0);
		for(int x = 1; x <= 99; ++x) {
			for(int y = 1; y <= 99; ++y) {
				point P(x, y);
				if(not collinear) {
					auto det1 = det(A, B, P), det2 = det(B, C, P), det3 = det(C, A, P);
					if((det1 > -EPS && det2 > -EPS && det3 > -EPS) ||
					   (det1 < +EPS && det2 < +EPS && det3 < +EPS)) {
						++count;
					}
				} else {
					segment s(A, B), r(B, C);
					if(s.contains(P)) {
						++count;
					} else if(r.contains(P)) {
						++count;
					}
				}
			}
		}

		printf("%4d\n", count);
	}

	return 0;
}

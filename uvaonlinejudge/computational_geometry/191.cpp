#include <bits/stdc++.h>

#define EPS 1e-6

using namespace std;

bool equals(double x, double y) {
	return fabs(x - y) < EPS;
}

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

	bool operator<(const point& other) const {
		return fabs(x - other.x) < EPS ? (y - other.y) < -EPS : (x - other.x) < -EPS;
	}

	bool operator==(const point& other) const {
		return equals(x, other.x) and equals(y, other.y);
	}
};

double det(const point& a, const point& b, const point& c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

class segment {
public:
	point p, q;

	segment(const point& a, const point& b) {
		p = min(a, b);
		q = max(a, b);
	}

	bool degenerated() {
		return p == q;
	}

	bool contains(const point& a) {
		return equals(p.x, q.x) ? (p.y - EPS < a.y && q.y + EPS > a.y) :
					  (p.x - EPS < a.x && q.x + EPS > a.x);
	}

	bool intersects(segment& s) {
		auto det1 = det(p, q, s.p);
		auto det2 = det(p, q, s.q);
		auto det3 = det(s.p, s.q, p);
		auto det4 = det(s.p, s.q, q);

		return (equals(det1, 0) && contains(s.p)) || (equals(det2, 0) && contains(s.q)) ||
		       (equals(det3, 0) && s.contains(p)) || (equals(det4, 0) && s.contains(q)) || (det1 * det2 < -EPS && det3 * det4 < -EPS);
	}
};

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		double x1, y1, x2, y2, xl, yt, xr, yb;
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		scanf("%lf %lf %lf %lf", &xl, &yt, &xr, &yb);

		point p(x1, y1), q(x2, y2), left_corner(min(xl, xr), min(yb, yt)), right_corner(max(xl, xr), max(yb, yt));
		segment s(p, q), rectangle[4] = {segment(point(xl, yb), point(xl, yt)),
						 segment(point(xl, yt), point(xr, yt)),
						 segment(point(xr, yt), point(xr, yb)),
						 segment(point(xr, yb), point(xl, yb))};

		bool contains_p = !(left_corner.x > p.x) && !(p.x > right_corner.x) && !(left_corner.y > p.y) && !(p.y > right_corner.y);
		bool contains_q = !(left_corner.x > q.x) && !(q.x > right_corner.x) && !(left_corner.y > q.y) && !(q.y > right_corner.y);
		bool ans = contains_p || contains_q;
		if(not s.degenerated()) {
			for(int i = 0; i < 4; ++i) {
				if(rectangle[i].intersects(s)) {
					ans = true;
				}
			}
		}

		printf(ans ? "T\n" : "F\n");
	}

	return 0;
}

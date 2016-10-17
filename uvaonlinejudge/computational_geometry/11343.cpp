#include <bits/stdc++.h>

#define EPS 1e-6

using namespace std;

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

	bool operator<(const point& other) const {                                                                                                                  
		return fabs(x - other.x) < EPS ? (y - other.y) < -EPS : (x - other.x) < -EPS;
	}
};

bool equals(double x, double y) {
	return fabs(x - y) < EPS;
}

double det(const point& p, const point& q, const point& r) {
	return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

class segment {
public:
	point p, q;

	segment(point a, point b) {
		p = min(a, b);
		q = max(a, b);
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
		int n;
		scanf("%d", &n);

		vector<segment> segments;
		for(int i = 1; i <= n; ++i) {
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			segments.push_back(segment(point(x1, y1), point(x2, y2)));
		}

		vector<int> intersections(n + 1, 0);
		for(int i = 0; i < n - 1; ++i) {
			for(int j = i + 1; j < n; ++j) {
				if(segments[i].intersects(segments[j])) {
					intersections[i]++;
					intersections[j]++;
				}
			}
		}

		int ans = 0;
		for(int i = 0; i < n; ++i) {
			if(intersections[i] == 0) ++ans;
		}

		printf("%d\n", ans);
	}

	return 0;
}

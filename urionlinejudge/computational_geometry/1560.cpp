#include <bits/stdc++.h>

#define EPS 1e-9

using namespace std;

bool equals(double x, double y) { return fabs(x - y) < EPS; }

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}
};

double cross_product(const point& p, const point& q, const point& r) {
	return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

class triangle {
private:
	point a, b, c;

public:
	triangle(point av, point bv, point cv) : a(av), b(bv), c(cv) {}

	bool contains(const point& p) {
		double d1 = cross_product(a, b, p);
		double d2 = cross_product(b, c, p);
		double d3 = cross_product(c, a, p);
		return equals(d1, 0) or equals(d2, 0) or equals(d3, 0) or (d1 > EPS and d2 > EPS and d3 > EPS) or (d1 < -EPS and d2 < -EPS and d3 < -EPS);
	}
};

int main(void) {
	int n, m;
	while(~scanf("%d %d", &n, &m)) {
		vector<point> black(n), white(m);
		for(int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			black[i] = point(x, y);
		}

		for(int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			white[i] = point(x, y);
		}

		int ans = 0;
		for(int i = 0; i < n - 2; ++i) {
			for(int j = i + 1; j < n - 1; ++j) {
				for(int k = j + 1; k < n; ++k) {
					triangle t(black[i], black[j], black[k]);
					int count = 0;
					for(auto p : white) {
						count += t.contains(p);
					}
					ans += count * count;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

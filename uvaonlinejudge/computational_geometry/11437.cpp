#include <bits/stdc++.h>

using namespace std;

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}
};

double cross_product(const point& p, const point& q, const point& r) {
	return (q.x - p.x) * (r.y - p.y) - (r.x - p.x) * (q.y - p.y);
}

int main(void) {
	int tc, magic_number = 14;
	scanf("%d", &tc);
	while(tc--) {
		double x1, y1, x2, y2, x3, y3;
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
		point p(x1, y1), q(x2, y2), r(x3, y3);
		printf("%.lf\n", cross_product(p, q, r) / magic_number);
	}
	return 0;
}

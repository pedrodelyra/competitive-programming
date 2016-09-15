#include <bits/stdc++.h>

#define EPS 1e-9

using namespace std;

bool equals(double x, double y) { return fabs(x - y) < EPS; }

class point {
public:
	double x, y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

	bool operator==(const point& other) const {
		return equals(this->x, other.x) && equals(this->y, other.y);
	}

	bool operator<(const point& other) const {
		return equals(this->x, other.x) ? this->y < other.y - EPS : this->x < other.x - EPS;
	}
};

int main(void) {
	double x1, y1, x2, y2, x3, y3, x4, y4;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) != EOF) {
		point A(x1, y1), B(x2, y2), C(x3, y3), D(x4, y4), intersection;
		vector<point> points = { A, B, C, D };
		sort(points.begin(), points.end());

		for(int i = 1; i < points.size(); ++i) {
			if(points[i] == points[i - 1]) {
				intersection = points[i];
				points.erase(points.begin() + i);
				points.erase(points.begin() + i - 1);
				break;
			}
		}

		A = points[0], B = points[1];
		printf("%.3lf %.3lf\n", A.x + B.x - intersection.x, A.y + B.y - intersection.y);
	}

	return 0;
}

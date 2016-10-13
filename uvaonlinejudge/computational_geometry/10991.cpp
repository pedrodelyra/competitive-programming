#include <bits/stdc++.h>

using namespace std;

class triangle {
public:
	double a, b, c;

	triangle(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

	double alpha() const {
		return acos((a * a - b * b - c * c) / (- 2 * b * c));
	}

	double beta() const {
		return acos((b * b - a * a - c * c) / (- 2 * a * c));
	}

	double gamma() const {
		return acos((c * c - a * a - b * b) / (- 2 * a * b));
	}

	double perimeter() const {
		return a + b + c;
	}

	double area() const {
		double s = perimeter() / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}
};

int main(void) {
	int n;
	scanf("%d", &n);
	while(n--) {
		double r1, r2, r3;
		scanf("%lf %lf %lf", &r1, &r2, &r3);

		triangle t(r2 + r3, r1 + r3, r1 + r2);
		double _1st_sector = t.alpha() * r1 * r1 / 2.0;
		double _2nd_sector = t.beta()  * r2 * r2 / 2.0;
		double _3rd_sector = t.gamma() * r3 * r3 / 2.0;
		printf("%.6lf\n", t.area() - _1st_sector - _2nd_sector - _3rd_sector);
	}

	return 0;
}

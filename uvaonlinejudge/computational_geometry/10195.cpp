#include <bits/stdc++.h>

using namespace std;

class triangle {
private:
	double a, b, c;

public:
	triangle(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

	double perimeter() const {
		return a + b + c;
	}

	double area() const {
		auto s = perimeter() / 2.0;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}

	double inradius() const {
		return (2 * area()) / perimeter();
	}
};

int main(void) {
	double a, b, c;
	while(~scanf("%lf %lf %lf", &a, &b, &c)) {
		triangle t(a, b, c);
		double ans = t.inradius();
		printf("The radius of the round table is: %.3lf\n", ans != ans ? 0 : ans);
	}

	return 0;
}

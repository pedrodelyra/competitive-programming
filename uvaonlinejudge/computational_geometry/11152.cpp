#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

class triangle {
private:
	double a, b, c;

public:
	triangle(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

	double perimeter() const {
		return a + b + c;
	}

	double area() const {
		auto s = perimeter() / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}

	double inradius() const {
		return (2 * area()) / perimeter();
	}

	double circumradius() const {
		return (a * b * c) / (4 * area());
	}
};

int main(void) {
	int a, b, c;
	while(~scanf("%d %d %d", &a, &b, &c)) {
		triangle t(a, b, c);
		double circumcircle_area = pi * t.circumradius() * t.circumradius();
		double incircle_area = pi * t.inradius() * t.inradius();
		printf("%.4lf %.4lf %.4lf\n", circumcircle_area - t.area(), t.area() - incircle_area, incircle_area);
	}

	return 0;
}

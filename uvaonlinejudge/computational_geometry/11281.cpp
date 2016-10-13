#include <bits/stdc++.h>

#define EPS 1e-12

using namespace std;

const double PI = acos(-1.0);

class triangle {
public:
	double a, b, c;

	triangle(double av, double bv, double cv) : a(av), b(bv), c(cv) {}

	double perimeter() const {
		return a + b + c;
	}

	double area() const {
		auto s = perimeter() / 2.0;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}

	double circumradius() const {
		return (a * b * c) / (4 * area());
	}

	double max_side() const {
		if(a > b + EPS && a > c + EPS) {
			return a;
		} else if(b > c + EPS) {
			return b;
		} else {
			return c;
		}
	}

	bool obtuse() const {
		auto AB = acos((c * c - a * a - b * b) / (-2 * a * b));
		auto AC = acos((b * b - a * a - c * c) / (-2 * a * c));
		auto BC = acos((a * a - b * b - c * c) / (-2 * b * c));
		return (AB > PI / 2.0 + EPS) || (AC > PI / 2.0 + EPS) || (BC > PI / 2.0 + EPS);
	}
};

int main(void) {
	int n;
	scanf("%d", &n);

	vector<double> diameters(n + 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%lf", &diameters[i]);
	}

	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		double a, b, c;
		scanf("%lf %lf %lf", &a, &b, &c);

		triangle t(a, b, c);
		vector<int> fits;
		for(int j = 1; j <= n; ++j) {
			if(t.obtuse()) {
				if(t.max_side() < diameters[j] + EPS) {
					fits.push_back(j);
				}
			} else {
				if(2 * t.circumradius() < diameters[j] + EPS) {
					fits.push_back(j);
				}
			}
		}

		if(fits.size() > 0) {
			printf("Peg %c will fit into hole(s):", i + 'A');
			for(auto& u : fits)
				printf(" %d", u);
			printf("\n");
		} else {
			printf("Peg %c will not fit into any holes\n", i + 'A');
		}
	}

	return 0;
}

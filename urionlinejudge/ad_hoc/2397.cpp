#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

bool equals(double x, double y) { return fabs(x - y) < eps; }

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	double alpha = acos((a * a - b * b - c * c) / (-2.0 * b * c));
	double gamma = acos((b * b - a * a - c * c) / (-2.0 * a * c));
	double theta = acos((c * c - a * a - b * b) / (-2.0 * a * b));
	double right = acos(0);
	if(a >= b + c || b >= a + c || c >= a + b) {
		printf("n\n");
	} else if(equals(alpha, right) || equals(gamma, right) || equals(theta, right)) {
		printf("r\n");
	} else if(alpha < right && gamma < right && theta < right) {
		printf("a\n");
	} else {
		printf("o\n");
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

int main(void) {
	double l;
	while(~scanf("%lf", &l)) {
		// 2 * ∫ l - sqrt(l² - x²) dx from 0 to l ÷ 2
		double checked = l * l - l * l * asin(0.5) - l * l * sqrt(3) / 4;
		double  dotted = l * l - pi * l * l / 4 - 2 * checked;
		double striped = l * l - 4 * dotted - 4 * checked;
		printf("%.3lf %.3lf %.3lf\n", striped, 4 * dotted, 4 * checked);
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		double dist, length;
		scanf("%lf %lf", &dist, &length);
		double a = length / 2, b = sqrt(a * a - dist * dist / 4);
		printf("%.3lf\n", pi * a * b);
	}
	return 0;
}

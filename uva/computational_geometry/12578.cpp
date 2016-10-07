#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int length;
		scanf("%d", &length);

		double radius = length / 5.0, width = 0.6 * length;
		printf("%.2lf %.2lf\n", pi * radius * radius, length * width - pi * radius * radius);
	}
	return 0;
}

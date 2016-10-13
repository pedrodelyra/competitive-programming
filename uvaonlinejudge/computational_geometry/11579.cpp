#include <bits/stdc++.h>

using namespace std;

double triangle_area(double a, double b, double c) {
	if(a >= (b + c) or b >= (a + c) or c >= (a + b)) {
		return 0;
	} else {
		double s = (a + b + c) / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n;
		scanf("%d", &n);

		vector<double> sides(n);
		for(int i = 0; i < n; ++i) {
			scanf("%lf", &sides[i]);
		}
		sort(sides.begin(), sides.end());

		double max_area = 0;
		for(int i = 2; i < n; ++i) {
			max_area = max(max_area, triangle_area(sides[i], sides[i - 1], sides[i - 2]));
		}
		printf("%.2lf\n", max_area);
	}
	return 0;
}

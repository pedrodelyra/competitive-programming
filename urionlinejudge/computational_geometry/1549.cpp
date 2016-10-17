#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0), eps = 1e-9;

bool equals(double x, double y) { return fabs(x - y) <= eps; }

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		double n, l, b, B, H;
		scanf("%lf %lf %lf %lf %lf", &n, &l, &b, &B, &H);
		double ans, theta = pi / 2 - atan2(H, B - b), V = l / n, low = 0, high = H;
		while(low < high) {
			double h = (low + high) / 2;
			double r = b, R = b + h * tan(theta);
			double vol = pi * h / 3 * (R * R + R * r + r * r);
			if(equals(vol, V)) {
				ans = h;
				break;
			} else if(vol + eps < V) {
				low = h;
			} else {
				high = h;
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}

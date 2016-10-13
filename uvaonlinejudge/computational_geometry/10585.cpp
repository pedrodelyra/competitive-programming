#include <bits/stdc++.h>

#define EPS 1e-6

using namespace std;
using ii = pair<int, int>;

class point {
public:
	double x;
	double y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}

	bool equals(point other) {
		return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
	}
};

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n;
		scanf("%d", &n);

		vector<ii> points(n);
		for(int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			points[i] = ii(x, y);
		}
		if(n == 1) { printf("yes\n"); continue; }

		sort(points.begin(), points.end());

		int mid = n >> 1, ans = true;
		point center = point((points[0].first + points[n - 1].first) / 2.0, (points[0].second + points[n - 1].second) / 2.0);
		for(int i = 1; i < mid; ++i) {
			point current_center = point((points[i].first + points[n - i - 1].first) / 2.0, (points[i].second + points[n - i - 1].second) / 2.0);

			if(not center.equals(current_center)) ans = false;
		}

		if((n & 1) && not center.equals(point(points[mid].first, points[mid].second))) ans = false;

		printf(ans ? "yes\n" : "no\n");
	}

	return 0;
}

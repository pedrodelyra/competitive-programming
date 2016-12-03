#include <bits/stdc++.h>

using namespace std;

class point {
public:
	int x, y;

	point(int xv = 0, int yv = 0) : x(xv), y(yv) {}

	bool operator<(const point& rhs) const {
		return x == rhs.x ? y < rhs.y : x < rhs.x;
	}
};

int cross_product(const point& p, const point& q, const point& r) {
	return (q.x - p.x) * (r.y - p.y) - (r.x - p.x) * (q.y - p.y);
}

vector<point> convex_hull(vector<point>& points) {
	int n = points.size(), k = 0;
	sort(points.begin(), points.end());
	vector<point> hull(n << 1);
	for(int i = 0; i < n; ++i) {
		while(k >= 2 && cross_product(hull[k - 2], hull[k - 1], points[i]) < 0) --k;
		hull[k++] = points[i];
	}
	for(int i = n - 2, t = k + 1; i >= 0; --i) {
		while(k >= t && cross_product(hull[k - 2], hull[k - 1], points[i]) < 0) --k;
		hull[k++] = points[i];
	}
	hull.resize(max(k - 1, 0));
	sort(hull.begin(), hull.end());
	return hull;
}

int solve(vector<point> points, int count) {
	int n = points.size();
	if(n <= 2) {
		return count;
	} else {
		vector<point> hull = convex_hull(points), new_set;
		set_difference(points.begin(), points.end(), hull.begin(), hull.end(), inserter(new_set, new_set.begin()));
		return solve(new_set, count + 1);
	}
}

int main(void) {
	int n;
	while(scanf("%d", &n), n) {
		vector<point> points(n);
		for(int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			points[i] = point(x, y);
		}
		printf(solve(points, 0) & 1 ? "Take this onion to the lab!\n" : "Do not take this onion to the lab!\n");
	}
	return 0;
}

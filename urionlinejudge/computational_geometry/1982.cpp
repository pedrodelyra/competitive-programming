#include <bits/stdc++.h>

using namespace std;

class point {
public:
	int x, y;

	point(int xv = 0, int yv = 0) : x(xv), y(yv) {}

	double distance(const point& p) {
		return hypot(x - p.x, y - p.y);
	}

	bool operator<(const point& rhs) const {
		return x == rhs.x ? y < rhs.y : x < rhs.x;
	}
};

class polygon {
private:
	vector<point> vertices;

public:
	polygon(const vector<point>& vs) : vertices(vs) {}

	double perimeter() {
		double p = 0;
		for(int i = 1; i < vertices.size(); ++i) {
			p += vertices[i].distance(vertices[i - 1]);
		}
		return p;
	}
};

int cross_product(const point& p, const point& q, const point& r) {
	return (q.x - p.x) * (r.y - p.y) - (r.x - p.x) * (q.y - p.y);
}

polygon convex_hull(vector<point>& points) {
	int n = points.size(), k = 0;
	sort(points.begin(), points.end());
	vector<point> hull(n << 1);
	for(int i = 0; i < n; ++i) {
		while(k >= 2 && cross_product(hull[k - 2], hull[k - 1], points[i]) <= 0) --k;
		hull[k++] = points[i];
	}
	for(int i = n - 2, t = k + 1; i >= 0; --i) {
		while(k >= t && cross_product(hull[k - 2], hull[k - 1], points[i]) <= 0) --k;
		hull[k++] = points[i];
	}
	hull.resize(k);
	return polygon(hull);
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
		auto hull = convex_hull(points);
		printf("Tera que comprar uma fita de tamanho %.2lf.\n", hull.perimeter());
	}
	return 0;
}

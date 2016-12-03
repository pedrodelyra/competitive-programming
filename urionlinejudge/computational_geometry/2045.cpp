#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0), eps = 1e-8;

bool equals(double x, double y) { return fabs(x - y) < eps; }

class point {
public:
	int x, y;

	point(int xv = 0, int yv = 0) : x(xv), y(yv) {}

	double distance(const point& p) {
		return hypot(x - p.x, y - p.y);
	}
};

class segment {
public:
	point a, b;

	segment(const point& av, const point& bv) : a(av), b(bv) {}

	bool contains(const point& p) const {
		if(a.x == b.x) {
			return min(a.y, b.y) <= p.y and p.y <= max(a.y, b.y);
		} else {
			return min(a.x, b.x) <= p.x and p.x <= max(a.x, b.x);
		}
	}
};

double angle(const point& p, const point& q, const point& r) {
	auto ux = p.x - q.x;
	auto uy = p.y - q.y;

	auto vx = p.x - r.x;
	auto vy = p.y - r.y;

	auto num = 1LL * ux * vx + 1LL * uy * vy;
	auto den = hypot(ux, uy) * hypot(vx, vy);
	return acos(num / den);
}

long long cross_product(const point& p, const point& q, const point& r) {
	return 1LL * (q.x - p.x) * (r.y - p.y) - 1LL * (r.x - p.x) * (q.y - p.y);
}


class polygon {
private:
	vector<point> vertices;
	int n;

public:
	polygon(const vector<point>& vs) : vertices(vs), n(vs.size()) {
		vertices.push_back(vertices[0]);
	}

	bool contains(const point& p, bool flag) {
		if(n < 3) return false;

		auto sum = 0.0;
		for (int i = 0; i < n; ++i) {
			auto d = cross_product(p, vertices[i], vertices[i + 1]);

			if(equals(d, 0) and segment(vertices[i], vertices[i + 1]).contains(p)) return flag;

			auto a = angle(p, vertices[i], vertices[i + 1]);

			sum += d > 0 ? a : -a;
		}
		return equals(fabs(sum), 2 * pi);
	}
};

int main(void) {
	int n, m, x, y, tc = 0;
	while(scanf("%d", &n), n) {
		vector<point> posts(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &x, &y);
			posts[i] = point(x, y);
		}
		polygon p(posts);
		scanf("%d %d %d", &x, &y, &m);
		point flag(x, y);
		vector<point> soldiers(m);
		for(int i = 0; i < m; ++i) {
			scanf("%d %d", &x, &y);
			soldiers[i] = point(x, y);
		}
		bool is_flag_inside = p.contains(flag, true);
		printf("Instancia %d\n", ++tc);
		for(int i = 0; i < m; ++i) {
			printf("soldado %d %s\n", i + 1, is_flag_inside ^ p.contains(soldiers[i], is_flag_inside) ? "espanhol" : "defender");
		}
		printf("\n");
	}
	return 0;
}

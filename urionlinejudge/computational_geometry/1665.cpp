#include <bits/stdc++.h>

using namespace std;

class point {
public:
	int x, y;

	point(int xv = 0, int yv = 0) : x(xv), y(yv) {}
};

class rectangle {
public:
	point p, q;

	rectangle(const point& pv, const point& qv) : p(pv), q(qv) {}

	bool intersects(rectangle& r) {
		int a = max(p.x, r.p.x), b = min(q.x, r.q.x);
		int c = max(p.y, r.p.y), d = min(q.y, r.q.y);
		return a < b and c < d;
	}
};

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, m = 1, w, h;
		scanf("%d %d %d", &n, &w, &h);
		vector<int> x(n << 1 | 1, 0), y(n << 1 | 1, 0);
		vector<rectangle> rectangles;
		for(int i = 0; i < n; ++i, m += 2) {
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			rectangles.push_back(rectangle(point(x1, y1), point(x2, y2)));
			x[m] = x1, x[m + 1] = x2;
			y[m] = y1, y[m + 1] = y2;
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());

		int width, height;
		scanf("%d %d", &width, &height);

		point ans(-1, -1);
		for(int i = 0; (!~ans.x and !~ans.y) and i < m; ++i) {
			if(y[i] + height > h) continue;
			for(int j = 0; (!~ans.x and !~ans.y) and j < m; ++j) {
				if(x[j] + width > w) continue;

				rectangle r(point(x[j], y[i]), point(x[j] + width, y[i] + height));
				bool fits = true;
				for(int k = 0; k < n; ++k) {
					if(r.intersects(rectangles[k])) fits = false;
				}
				if(fits) ans = point(x[j], y[i]);
			}
		}
		if(~ans.x and ~ans.y) {
			printf("%d %d\n", ans.x, ans.y);
		} else {
			printf("Fail!\n");
		}
	}
	return 0;
}

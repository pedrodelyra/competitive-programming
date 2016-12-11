#include <bits/stdc++.h>

using namespace std;

class point {
public:
	int x, y;

	point(int xv = 0, int yv = 0) : x(xv), y(yv) {}

	double distance(const point& p) {
		return hypot(x - p.x, y - p.y);
	}
};

vector<int> graph[1024];
int visiteds, visited[1024];

void dfs(int u) {
	visited[u] = true;
	for(auto& v : graph[u]) {
		if(not visited[v]) {
			dfs(v);
		}
	}
	++visiteds;
}

int main(void) {
	int n, range, root = 1;
	scanf("%d %d", &n, &range);
	vector<point> points(n + 1);
	for(int i = 1; i <= n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		points[i] = point(x, y);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			double dist = points[i].distance(points[j]);
			if(dist <= range) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	dfs(root);
	printf(visiteds == n ? "S\n" : "N\n");
	return 0;
}

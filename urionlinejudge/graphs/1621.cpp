#include <bits/stdc++.h>

#define MAX 512
#define oo 0x3f3f3f3f

using namespace std;
using ii = pair<int, int>;
using vii = vector<ii>;

char grid[MAX][MAX];
int  dist[MAX][MAX];
ii  furthest_point;
vii movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int bfs(ii source) {
	queue<ii> q;
	int x0, y0, xf, yf;
	tie(x0, y0) = source;
	memset(dist, oo, sizeof dist);
	dist[x0][y0] = 0;
	q.push(source);
	while(not q.empty()) {
		auto current_pos = q.front();
		int x, y;
		tie(x, y) = furthest_point = current_pos;
		for(auto& move : movements) {
			int dx = move.first, dy = move.second;
			if(grid[x + dx][y + dy] != '#' && dist[x + dx][y + dy] == oo) {
				dist[x + dx][y + dy] = dist[x][y] + 1;
				q.push(ii(x + dx, y + dy));
			}
		}
		q.pop();
	}
	tie(xf, yf) = furthest_point;
	return dist[xf][yf];
}

int main(void) {
	int n, m;
	while(scanf("%d %d", &n, &m), n | m) {
		ii source;
		memset(grid, '#', sizeof grid);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf(" %c", &grid[i][j]);
				if(grid[i][j] != '#') source = ii(i, j);
			}
		}

		bfs(source);
		printf("%d\n", bfs(furthest_point));
	}

	return 0;
}

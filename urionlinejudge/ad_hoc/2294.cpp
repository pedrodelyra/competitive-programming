#include <bits/stdc++.h>

#define EXIT	0
#define CRYSTAL 2
#define GUGO	3
#define oo	0x2f2f2f2f

using namespace std;
using ii  = pair<int, int>;
using vii = vector<ii>;

int grid[15][15];
int dist[15][15];
vii  movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int bfs(int x0, int y0) {
	queue<ii> q;
	memset(dist, oo, sizeof dist), dist[x0][y0] = 0;
	q.push(ii(x0, y0));
	while(not q.empty()) {
		auto current_pos = q.front();
		auto x = current_pos.first, y = current_pos.second;
		for(auto& move : movements) {
			int dx = move.first, dy = move.second;
			if(~grid[x + dx][y + dy] and dist[x + dx][y + dy] == oo) {
				dist[x + dx][y + dy] = dist[x][y] + 1;
				if(grid[x + dx][y + dy] == EXIT) {
					return dist[x + dx][y + dy];
				} else {
					q.push(ii(x + dx, y + dy));
				}
			}
		}
		q.pop();
	}
	return oo;
}

int main(void) {
	int n, m, x0, y0;
	scanf("%d %d", &n, &m);
	memset(grid, -1, sizeof grid);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &grid[i][j]);
			if(grid[i][j] == GUGO) x0 = i, y0 = j;
			if(grid[i][j] == CRYSTAL) grid[i][j] = -1;
		}
	}
	printf("%d\n", bfs(x0, y0));
	return 0;
}

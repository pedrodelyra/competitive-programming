#include <bits/stdc++.h>

#define oo 0x2f2f2f2f

using namespace std;
using state = tuple<int, int, int>;
using vii = vector<pair<int, int>>;

int grid[64][64], dist[64][64][8192];
vii movements = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int bfs(int n, int m) {
	queue<state> q;
	memset(dist, oo, sizeof dist), dist[1][1][0] = 0;
	q.push(state(1, 1, 0));
	while(not q.empty()) {
		auto current_state = q.front();
		int x, y, turn;
		tie(x, y, turn) = current_state;

		if(x == n and y == m) return dist[x][y][turn];

		for(auto& move : movements) {
			int dx = move.first, dy = move.second;
			if(dist[x + dx][y + dy][turn + 1] == oo and ~grid[x + dx][y + dy] and (grid[x + dx][y + dy] + turn) % 10 <= (grid[x][y] + turn) % 10 + 1) {
				dist[x + dx][y + dy][turn + 1] = dist[x][y][turn] + 1;
				q.push(state(x + dx, y + dy, turn + 1));
			}
		}
		q.pop();
	}
	return oo;
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	memset(grid, -1, sizeof grid);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}
	printf("%d\n", bfs(n, m));
	return 0;
}

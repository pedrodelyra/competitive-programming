#include <bits/stdc++.h>

#define MAX 64

using namespace std;
using ii  = pair<int, int>;
using iii = tuple<int, int, int>;

char grid[MAX][MAX];
bool is_lake, visited[MAX][MAX];
vector<ii> movements = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(int x, int y) {
	int vis = 1;
	visited[x][y] = true;
	for(auto& move : movements) {
		int dx = move.first, dy = move.second;
		if(not grid[x + dx][y + dy]) {
			is_lake = false;
		} else if(grid[x + dx][y + dy] == '.' and not visited[x + dx][y + dy]) {
			vis += dfs(x + dx, y + dy);
		}
	}
	return vis;
}

void flood_fill(int x, int y) {
	grid[x][y] = '*';
	for(auto& move : movements) {
		int dx = move.first, dy = move.second;
		if(grid[x + dx][y + dy] == '.') {
			flood_fill(x + dx, y + dy);
		}
	}
}

int main(void) {
	int n, m, k, x = 0;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf(" %c", &grid[i][j]);
		}
	}
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1, cells; j <= m; ++j) {
			if(not visited[i][j] and grid[i][j] == '.') {
				is_lake  = true;
				cells = dfs(i, j);
				if(is_lake) {
					pq.push(iii(cells, i, j));
				}
			}
		}
	}
	int changes = 0;
	while(pq.size() > k) {
		auto current_pos = pq.top();
		int cells, i, j;
		tie(cells, i, j) = current_pos;
		flood_fill(i, j);
		changes += cells;
		pq.pop();
	}
	printf("%d\n", changes);
	for(int i = 1; i <= n; ++i) {
		printf("%s\n", grid[i] + 1);
	}
	return 0;
}

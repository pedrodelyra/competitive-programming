#include <bits/stdc++.h>

#define MAX 128
#define oo  0x3f3f3f3f

using namespace std;
using vii = vector<pair<int, int>>;
using state = tuple<int, int, int>;

char grid[MAX][MAX];
int  dist[MAX][MAX][MAX];
vii  movements = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool is_door(char cell) { return 'A' <= cell and cell <= 'G'; }

bool has_key(char cell) { return 'a' <= cell and cell <= 'g'; }

int opening_key(char door) { return 1 << (door - 'A'); }

int key_mask(char key) { return 1 << (key - 'a'); }

int bfs(int x0, int y0) {
	queue<state> q;
	memset(dist, oo, sizeof dist);
	dist[x0][y0][0] = 0;
	q.push(state(x0, y0, 0));
	while(not q.empty()) {
		auto current_state = q.front();
		int x, y, mask;
		tie(x, y, mask) = current_state;

		if(grid[x][y] == '*') return dist[x][y][mask];

		for(auto& move : movements) {
			int dx = move.first, dy = move.second;
			if(grid[x + dx][y + dy] != '#') {
				if(is_door(grid[x + dx][y + dy])) {
					if(mask & opening_key(grid[x + dx][y + dy])) {
						if(dist[x + dx][y + dy][mask] == oo) {
							dist[x + dx][y + dy][mask] = dist[x][y][mask] + 1;
							q.push(state(x + dx, y + dy, mask));
						}
					}
				} else if(has_key(grid[x + dx][y + dy])) {
					int k = key_mask(grid[x + dx][y + dy]);
					if(dist[x + dx][y + dy][mask | k] == oo) {
						dist[x + dx][y + dy][mask | k] = dist[x][y][mask] + 1;
						q.push(state(x + dx, y + dy, mask | k));
					}
				} else if(dist[x + dx][y + dy][mask] == oo) {
					dist[x + dx][y + dy][mask] = dist[x][y][mask] + 1;
					q.push(state(x + dx, y + dy, mask));
				}
			}
		}
		q.pop();
	}
	return oo;
}

int main(void) {
	int n, m;
	memset(grid, '#', sizeof grid);
	while(~scanf(" %s", grid[++n] + 1)) {
		m = strlen(grid[n]);
		grid[n][m] = '#';
	}
	int x, y;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(grid[i][j] == '@') {
				x = i, y = j;
			}
		}
	}
	int min_moves = bfs(x, y);
	printf(min_moves < oo ? "%d\n" : "--\n", min_moves);
	return 0;
}

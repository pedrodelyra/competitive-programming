#include <bits/stdc++.h>

#define MAX 27
#define oo  0x2f2f2f2f

using namespace std;
using ii  = pair<int, int>;
using vii = vector<ii>;
using state = tuple<int, int, int, int, int>;

char grid[MAX][MAX], door[MAX][MAX];
int  pass, visited[MAX][MAX][MAX][MAX][MAX + 5], dist[MAX][MAX][MAX][MAX][MAX + 5];
vii  movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int num_keys(int mask) {
	int count = 0;
	while(mask) {
		count += mask & 1;
		mask >>= 1;
	}
	return count;
}

ii bfs(int x1, int y1, int x2, int y2) {
	queue<state> q;
	dist[x1][y1][x2][y2][0] = 0;
	visited[x1][y1][x2][y2][0] = ++pass;
	q.push(state(x1, y1, x2, y2, 0));
	int min_dist = oo, min_keys = oo;
	while(not q.empty()) {
		auto current_state = q.front(); q.pop();
		int cat_x, cat_y, box_x, box_y, mask;
		tie(cat_x, cat_y, box_x, box_y, mask) = current_state;

		int current_dist = dist[cat_x][cat_y][box_x][box_y][mask], keys = num_keys(mask);
		if(grid[box_x][box_y] == 'x') {
			if(min_keys > keys) {
				min_keys = keys;
				min_dist = current_dist;
			} else if(min_keys == keys) {
				min_dist = min(min_dist, current_dist);
			}
		}

		for(auto& move : movements) {
			int dx = move.first, dy = move.second;
			if(~grid[cat_x + dx][cat_y + dy]) {
				if(cat_x + dx == box_x and cat_y + dy == box_y) {
					if(~grid[box_x + dx][box_y + dy] and (not door[box_x + dx][box_y + dy] or (mask & door[box_x + dx][box_y + dy]))) {
						if(visited[cat_x + dx][cat_y + dy][box_x + dx][box_y + dy][mask] != pass) {
							dist[cat_x + dx][cat_y + dy][box_x + dx][box_y + dy][mask] = current_dist + 1;
							visited[cat_x + dx][cat_y + dy][box_x + dx][box_y + dy][mask] = pass;
							q.push(state(cat_x + dx, cat_y + dy, box_x + dx, box_y + dy, mask));
						}
					}
				} else if(visited[cat_x + dx][cat_y + dy][box_x][box_y][mask | door[cat_x + dx][cat_y + dy]] != pass) {
					dist[cat_x + dx][cat_y + dy][box_x][box_y][mask | door[cat_x + dx][cat_y + dy]] = current_dist + 1;
					visited[cat_x + dx][cat_y + dy][box_x][box_y][mask | door[cat_x + dx][cat_y + dy]] = pass;
					q.push(state(cat_x + dx, cat_y + dy, box_x, box_y, mask | door[cat_x + dx][cat_y + dy]));
				}
			}
		}
	}
	return ii(min_keys, min_dist);
}

int main(void) {
	int n, m;
	while(~scanf("%d %d", &n, &m)) {
		ii cat, box;
		memset(grid, -1, sizeof grid);
		memset(door,  0, sizeof door);
		for(int i = 1, k = 0; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf(" %c", &grid[i][j]);
				switch(grid[i][j]) {
					case '*':
						grid[i][j] = -1;
						break;
					case 'j':
						cat = ii(i, j);
						break;
					case 'b':
						box = ii(i, j);
						break;
					case '#':
						door[i][j] = 1 << k++;
						break;
				}
			}
		}
		auto ans = bfs(cat.first, cat.second, box.first, box.second);
		printf(ans.second < oo ? "%d %d\n" : "-1\n", ans.first, ans.second);
	}
	return 0;
}

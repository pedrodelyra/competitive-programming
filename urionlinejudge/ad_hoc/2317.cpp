#include <bits/stdc++.h>

#define MAX 255

using namespace std;
using ii = pair<int, int>;

char grid[MAX][MAX];
bool visited[MAX][MAX];
int  w, s;
vector<ii> movements = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int x, int y) {
	visited[x][y] = true;
	for(auto& move : movements) {
		auto dx = move.first, dy = move.second;
		if(not visited[x + dx][y + dy] and grid[x + dx][y + dy] != '#') {
			dfs(x + dx, y + dy);
		}
	}
	w += grid[x][y] == 'v';
	s += grid[x][y] == 'k';
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	memset(grid, '#', sizeof grid);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf(" %c", &grid[i][j]);
		}
	}

	int wolves = 0, sheep = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(not visited[i][j]) {
				w = s = 0;
				dfs(i, j);
				if(w >= s) {
					s = 0;
				} else {
					w = 0;
				}
				wolves += w, sheep += s;
			}
		}
	}
	printf("%d %d\n", sheep, wolves);
	return 0;
}

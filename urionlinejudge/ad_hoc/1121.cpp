#include <bits/stdc++.h>

using namespace std;
using vii = vector<pair<int, int>>;

char grid[128][128];
map<char, int> char_to_dir = {{'N', 0}, {'L', 1}, {'S', 2}, {'O', 3}};
vii moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(void) {
	int n, m, k;
	while(scanf("%d %d %d", &n, &m, &k), n | m | k) {
		int x, y, dir;
		memset(grid, '#', sizeof grid);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf(" %c", &grid[i][j]);
				if(isalpha(grid[i][j])) {
					dir = char_to_dir[grid[i][j]];
					grid[i][j] = '.';
					x = i, y = j;
				}
			}
		}
		int ans = 0;
		while(k--) {
			char cmd;
			scanf(" %c", &cmd);
			if(cmd == 'F') {
				int dx, dy;
				tie(dx, dy) = moves[dir];
				if(grid[x + dx][y + dy] != '#')	{
					x += dx, y += dy;	
					if(grid[x][y] == '*') {
						grid[x][y] = '.';
						++ans;
					}
				}
			} else if(cmd == 'D') {
				dir = (dir + 1) % 4;
			} else {
				dir = (dir + 3) % 4;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

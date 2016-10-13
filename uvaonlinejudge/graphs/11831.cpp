#include <bits/stdc++.h>

#define MAX 128

using namespace std;
using ii = pair<int, int>;

char grid[MAX][MAX];
map<char, int> direction_id = {{'O', 0}, {'N', 1}, {'L', 2}, {'S', 3}};
ii moves[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}; 

ii operator+(const ii& x, const ii& y) {
	return {x.first + y.first, x.second + y.second};
}

int main(void) {
	int n, m, k;
	while(scanf("%d %d %d", &n, &m, &k), (n | m | k)) {
		int x, y, direction;
		memset(grid, '#', sizeof grid);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf(" %c", &grid[i][j]);
				if(grid[i][j] == 'N' || grid[i][j] == 'S' || grid[i][j] == 'L' || grid[i][j] == 'O') {
					x = i, y = j;
					direction = direction_id[grid[i][j]];
					grid[i][j] = '.';
				}
			}
		}

		int stickers = 0;
		while(k--) {
			char instruction;
			scanf(" %c", &instruction);

			if(instruction == 'D') {
				direction = (direction + 1) % 4;
			}
			
			if(instruction == 'E') {
				direction = (direction + 3) % 4;
			}
			
			if(instruction == 'F') {
				ii movement = moves[direction];
				int dx = movement.first, dy = movement.second;
				if(grid[x + dx][y + dy] != '#') {
					x += dx;
					y += dy;
				}
			}

			if(grid[x][y] == '*') {
				++stickers;
				grid[x][y] = '.';
			}

		}

		printf("%d\n", stickers);
	}

	return 0;
}

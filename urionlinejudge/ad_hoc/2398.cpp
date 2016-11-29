#include <bits/stdc++.h>

using namespace std;

int n, x[128], y[128], grid[128][128], hits[128][128];

bool valid_position(int i, int j) {
	return 1 <= i and i <= n and 1 <= j and j <= n;
}

int main(void) {
	int k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= k; ++i) {
		scanf("%d %d", &y[i], &x[i]);
		scanf("%d", &grid[x[i] = n - x[i]][++y[i]]);
	}

	for(int i = 1; i <= k; ++i) {
		for(int dx = -grid[x[i]][y[i]]; dx <= grid[x[i]][y[i]]; ++dx) {
			for(int dy = -grid[x[i]][y[i]]; dy <= grid[x[i]][y[i]]; ++dy) {
				if(valid_position(x[i] + dx, y[i] + dy) and abs(dx) + abs(dy) == grid[x[i]][y[i]]) {
					hits[x[i] + dx][y[i] + dy]++;
				}
			}
		}
	}

	int xf, yf, count = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(hits[i][j] == k) {
				xf = i;
				yf = j;
				++count;
			}
		}
	}
	printf(count == 1 ? "%d %d\n" : "-1 -1\n", yf - 1, n - xf);
	return 0;
}

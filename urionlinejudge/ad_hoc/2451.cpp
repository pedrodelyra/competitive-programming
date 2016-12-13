#include <bits/stdc++.h>

#define MAX 128

using namespace std;

char grid[MAX][MAX];

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf(" %c", &grid[i][j]);
		}
	}
	int ans = 0, foods = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = i & 1 ? 1 : n; i & 1 ? j <= n : j >= 1; i & 1 ? ++j : --j) {
			if(grid[i][j] == 'A') {
				foods = 0;
			} else if(grid[i][j] == 'o') {
				ans = max(ans, ++foods);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

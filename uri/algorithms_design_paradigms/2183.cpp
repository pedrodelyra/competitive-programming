#include <bits/stdc++.h>

#define ALL_KEYS ((1 << 5) - 1)
#define INF 10000

using namespace std;

unsigned n, m, dp[105][105][35][11];
char grid[105][105];
string power = "POWER";

unsigned min_cost(int x, int y, int mask, int k) {
        if(x == n && y == n) {
                return 0;
        } else if(grid[x][y] == '#') {
                return INF;
        } else if(~dp[x][y][mask][k]) {
                return dp[x][y][mask][k];
        }

        int old_mask = mask;
        for(int i = 0; power[i]; ++i) {
                if(grid[x][y] == power[i]) {
                        mask |= (1 << i);
                }
        }

        int old_k = k;
        if(mask == ALL_KEYS) {
                mask = 0;
                k = m + 1;
        }

        return dp[x][y][old_mask][old_k] = min(min_cost(x + 1, y, mask, k - (k > 0)), min_cost(x, y + 1, mask, k - (k > 0))) + (isdigit(grid[x][y]) && k == 0) * (grid[x][y] - '0');
} 

int main(void) {
        scanf("%d %d", &n, &m);
        memset(grid, '#', sizeof grid);
        for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                        scanf(" %c", &grid[i][j]);
                }
        }

        memset(dp, -1, sizeof dp);
        grid[1][1] = grid[n][n] = '0';
        int ans = min_cost(1, 1, 0, 0);
        printf("%d\n", ans < INF ? ans + 1 : -1);

        return 0;
}

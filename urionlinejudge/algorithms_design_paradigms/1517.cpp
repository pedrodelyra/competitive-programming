#include <bits/stdc++.h>

using namespace std;

int n, m, max_t, apples[25][25][1005], dp[25][25][1005];

bool valid_position(int x, int y) {
    return 1 <= x and x <= n and 1 <= y and y <= m;
}

int solve(int x, int y, int t) {
    if(t > max_t) {
        return 0;
    } else if(~dp[x][y][t]) {
        return dp[x][y][t];
    }
    int max_apples = 0;
    for(int dx = -1; dx <= 1; ++dx) {
        for(int dy = -1; dy <= 1; ++dy) {
            if(valid_position(x + dx, y + dy)) {
                max_apples = max(max_apples, solve(x + dx, y + dy, t + 1));
            }
        }
    }
    return dp[x][y][t] = max_apples + apples[x][y][t];
}

int main(void) {
    int k;
    while(scanf("%d %d %d", &n, &m, &k), n | m | k) {
        memset(apples, 0, sizeof apples);
        for(int i = 1; i <= k; ++i) {
            int x, y, t;
            scanf("%d %d %d", &x, &y, &t);
            apples[x][y][t] = 1;
            max_t = max(max_t, t + 1);
        }
        int x0, y0;
        scanf("%d %d", &x0, &y0);
        memset(dp, -1, sizeof dp);
        printf("%d\n", solve(x0, y0, 0));
    }
    return 0;
}

#include <bits/stdc++.h>

#define INF 0x1f1f1f1f

using namespace std;

int dp[10005][105];

int min_size(int n, int i) {
        if(n == 0) {
                return 0;
        } else if(n < 0 || i * i > n) {
                return INF;
        } else if(~dp[n][i]) {
                return dp[n][i];
        }

        return dp[n][i] = min(min_size(n - i * i, i) + 1, min_size(n, i + 1));
}

int main(void) {
        int tc;
        scanf("%d", &tc);
        memset(dp, -1, sizeof dp);
        while(tc--) {
                int n;
                scanf("%d", &n);
                printf("%d\n", min_size(n, 1));
        }

        return 0;
}

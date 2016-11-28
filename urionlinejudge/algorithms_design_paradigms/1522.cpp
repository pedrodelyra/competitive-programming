#include <bits/stdc++.h>

#define MAX 105
#define oo  1 << 20

using namespace std;

int a[MAX] = {-oo}, b[MAX] = {-oo}, c[MAX] = {-oo}, dp[MAX][MAX][MAX];

int solve(int i, int j, int k) {
        if(i == 0 and j == 0 and k == 0) {
                return 1;
        } else if(~dp[i][j][k]) {
                return dp[i][j][k];
        }
        int ans = 0;
        for(int mask = 1; ans == 0 and mask <= 7; ++mask) {
                int sum = ((mask & 1) ? a[i] : 0) + ((mask & 2) ? b[j] : 0) + ((mask & 4) ? c[k] : 0);
                if(sum >= 0 and sum % 3 == 0) {
                        ans = solve(i - (mask & 1), j - (mask >> 1 & 1), k - (mask >> 2 & 1));
                }
        }
        return dp[i][j][k] = ans;
}

int main(void) {
        int n;
        while(scanf("%d", &n), n) {
                for(int i = n; i >= 1; --i) {
                        scanf("%d %d %d", &a[i], &b[i], &c[i]);
                }
                memset(dp, -1, sizeof dp);
                printf("%d\n", solve(n, n, n));
        }
        return 0;
}

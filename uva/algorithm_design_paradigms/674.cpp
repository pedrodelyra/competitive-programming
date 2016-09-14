#include <bits/stdc++.h>

#define INF 0x1f1f1f1f

using namespace std;

int dp[10][10005], coins[] = {1, 5, 10, 25, 50};

int num_ways(int type, int change) {
        if(change == 0) {
                return 1;
        } else if(type == 5 || change < 0) {
                return 0;
        } else if(~dp[type][change]) {
                return dp[type][change];
        }

        return dp[type][change] = num_ways(type, change - coins[type]) + num_ways(type + 1, change);
}

int main(void) {
        int n;
        memset(dp, -1, sizeof dp);
        while(scanf("%d", &n) != EOF) {
                printf("%d\n", num_ways(0, n));
        }

        return 0;
}

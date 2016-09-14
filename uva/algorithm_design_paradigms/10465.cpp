#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

int n, m, t, dp[MAX];

int main(void) {
	while(scanf("%d %d %d", &n, &m, &t) != EOF) {
		memset(dp, -1, sizeof(dp));

                dp[0] = 0;
                for(int i = 1; i <= t; ++i) {
                        if(i >= n && ~dp[i - n]) dp[i] = dp[i - n] + 1;

                        if(i >= m && ~dp[i - m]) dp[i] = max(dp[i], dp[i - m] + 1);
                }

                if(~dp[t]) {
                        printf("%d", dp[t]);
                } else {
                        for(int i = t; i >= 0; --i) {
                                if(~dp[i]) {
                                        printf("%d %d", dp[i], t - i);
                                        break;
                                }
                        }
                }
                printf("\n");
	}

	return 0;
}

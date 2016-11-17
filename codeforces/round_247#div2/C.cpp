#include <bits/stdc++.h>

#define MAX 256
#define mod 1000000007

using namespace std;

int n, k, d, dp[MAX][2];

int solve(int x, bool used) {
	if(x == n and used) {
		return 1;
	} else if(x > n) {
		return 0;
	} else if(~dp[x][used]) {
		return dp[x][used];
	}
	int ans = 0;
	for(int i = 1; i <= k; ++i) {
		ans = (ans + solve(x + i, used | (i >= d))) % mod;
	}
	return dp[x][used] = ans;
}

int main(void) {
	scanf("%d %d %d", &n, &k, &d);
	memset(dp, -1, sizeof dp);
	printf("%d\n", solve(0, 0));
	return 0;
}

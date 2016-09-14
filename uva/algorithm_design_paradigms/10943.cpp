#include <bits/stdc++.h>

#define MAX 128
#define MOD 1000000

using namespace std;

int dp[MAX][MAX];

int num_ways(int n, int k) {
	if(k == 1) {
		return 1;
	} else if(~dp[n][k]) {
		return dp[n][k];
	}

	int result = 0;
	for(int x = 0; x <= n; ++x) {
		result += num_ways(n - x, k - 1) % MOD;
	}

	return dp[n][k] = result;
}

int main(void) {
	int n, k;
	while(scanf("%d %d", &n, &k), (n | k)) {
		memset(dp, -1, sizeof dp);
		printf("%d\n", num_ways(n, k) % MOD);
	}

	return 0;
}

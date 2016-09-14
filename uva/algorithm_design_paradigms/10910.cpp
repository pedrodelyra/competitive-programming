#include <bits/stdc++.h>

using namespace std;

int n, t, p, dp[80][80];

int num_ways(int i, int j) {
	if(i == n && j == 0) {
		return 1;
	} else if(i > n || j < 0) {
		return 0;
	} else if(~dp[i][j]) {
		return dp[i][j];
	}

	int result = 0;
	for(int k = p; k <= t; ++k) {
		result += num_ways(i + 1, j - k); 
	}

	return dp[i][j] = result;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d %d %d", &n, &t, &p);
		memset(dp, -1, sizeof dp);
		printf("%d\n", num_ways(0, t));
	}

	return 0;
}

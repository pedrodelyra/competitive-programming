#include <bits/stdc++.h>

#define MAX 1024
#define oo  0x2f2f2f2f

using namespace std;

int n, m, a[MAX], dp[MAX][MAX];

int solve(int i, int k) {
	if(i > n or k < 0) {
		return oo;
	} else if(i == n and k == 0) {
		return 0;
	} else if(~dp[i][k]) {
		return dp[i][k];
	}
	return dp[i][k] = min(solve(i + 1, k) + a[i] - a[i - 1], solve(i + 1, k - 1));
}

int main(void) {
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 1; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		memset(dp, -1, sizeof dp);
		printf("%d\n", solve(1, m - 1));
	}
	return 0;
}

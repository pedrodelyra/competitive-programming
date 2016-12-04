#include <bits/stdc++.h>

#define MAX 1024
#define oo  (1 << 30)

using namespace std;

int A[MAX], dp[MAX][MAX];

int solve(int i, int j) {
	if(j - i <= 1) {
		return A[i] == A[j] ? 1 : 2;
	} else if(~dp[i][j]) {
		return dp[i][j];
	} else {
		return dp[i][j] = min(solve(i + 1, j), min(solve(i, j - 1), A[i] == A[j] ? solve(i + 1, j - 1) : oo)) + 1;
	}
}

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &A[i]);
		}
		memset(dp, -1, sizeof dp);
		printf("Caso #%d: %d\n", tc, solve(1, n));
	}
	return 0;
}

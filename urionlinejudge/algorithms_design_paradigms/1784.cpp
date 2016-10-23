#include <bits/stdc++.h>

#define MAX 9
#define oo  0x2f2f2f2f

using namespace std;

int n, A[MAX], B[MAX], dp[1 << (MAX << 1)];

int gcd(int a, int b) {
	if(a == 0) {
		return b;
	} else {
		return gcd(b % a, a);
	}
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int solve(int mask) {
	if((1 << (n << 1)) - 1 == mask) {
		return 0;
	} else if(~dp[mask]) {
		return dp[mask];
	}
	int ans = oo;
	for(int i = 0; i < n; ++i) {
		if((mask >> i) & 1) continue;
		for(int j = 0; j < n; ++j) {
			if((mask >> (n + j)) & 1) continue;
			ans = min(ans, max(solve(mask | (1 << i) | (1 << (n + j))), lcm(A[i], B[j])));
		}
	}
	return dp[mask] = ans;
}

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &A[i]);
		}

		for(int i = 0; i < n; ++i) {
			scanf("%d", &B[i]);
		}
		memset(dp, -1, sizeof dp);
		printf("Caso #%d: %d\n", tc, solve(0));
	}
	return 0;
}

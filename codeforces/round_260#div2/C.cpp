#include <bits/stdc++.h>

#define MAX 100005

using namespace std;
using lld = long long int;

int f[MAX], A[MAX];
lld dp[MAX];

lld solve(int n) {
	if(n == 0 or n == 1) {
		return f[n];
	} else if(~dp[n]) {
		return dp[n];
	}
	return dp[n] = max(solve(n - 1), solve(n - 2) + f[n] * (lld) n);
}

int main(void) {
	int n, x = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);
		x = max(x, A[i]);
		f[A[i]]++;
	}
	memset(dp, -1, sizeof dp);
	printf("%lld\n", solve(x));
	return 0;
}

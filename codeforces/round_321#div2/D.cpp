#include <bits/stdc++.h>

#define MAX 19

using namespace std;
using lld = long long int;

int n, m, k;
lld a[MAX], c[MAX][MAX], dp[MAX][1 << MAX];

int setted_bits(int mask) {
	int count = 0;
	while(mask) {
		count += mask & 1;
		mask >>= 1;;
	}
	return count;
}

lld solve(int u, int mask) {
	if(setted_bits(mask) == m) {
		return a[u];
	} else if(~dp[u][mask]) {
		return dp[u][mask];
	}
	lld ans = 0;
	for(int i = 0; i < n; ++i) {
		if((mask >> i) & 1) continue;
		ans = max(ans, solve(i, (1 << i) | mask) + c[u][i]);
	}
	return dp[u][mask] = ans + a[u];
}

int main(void) {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	for(int i = 0; i < k; ++i) {
		int u, v, x;
		scanf("%d %d %d", &u, &v, &x);
		c[u - 1][v - 1] = x;
	}
	memset(dp, -1, sizeof dp);
	printf("%lld\n", solve(n, 0));
	return 0;
}

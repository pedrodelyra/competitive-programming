#include <bits/stdc++.h>

#define oo 0x2f2f2f2f

using namespace std;

int n, x, y, w, z, f[256], dp[256][64];

int solve(int i, int current_week) {
	if(i > n) {
		return current_week * y;
	} else if(~dp[i][current_week]) {
		return dp[i][current_week];
	}
	int ans = oo;
	if(current_week < f[i]) {
		ans = solve(i + 1, f[i]) + (f[i] - current_week) * x + f[i] * z;
	} else {
		for(int j = current_week; j >= f[i]; --j) {
			ans = min(ans, solve(i + 1, j) + (current_week - j) * y + (j - f[i]) * w + f[i] * z);
		}
	}
	return dp[i][current_week] = ans;
}

int main(void) {
	int tc = 0;
	while(scanf("%d", &n), n) {
		memset(dp, -1, sizeof dp);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &f[i]);
		}
		scanf("%d %d %d %d", &x, &y, &z, &w);
		printf("Instancia %d\n%d\n\n", ++tc, solve(1, 0));
	}
	return 0;
}

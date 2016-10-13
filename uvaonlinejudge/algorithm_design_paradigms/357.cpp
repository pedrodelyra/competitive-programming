#include <bits/stdc++.h>

#define MAX_VALUE 30005

using namespace std;
using ll = long long int;

int coins[] = {1, 5, 10, 25, 50};
ll dp[5][MAX_VALUE];

ll num_ways(int type, int current_change) {
	if(current_change == 0) {
		return 1;
	} else if(current_change < 0 || type == 5) {
		return 0;
	} else if(~dp[type][current_change]) {
		return dp[type][current_change];
	}

	return dp[type][current_change] = num_ways(type + 1, current_change) + num_ways(type, current_change - coins[type]);
}

int main(void) {
	int n;
	memset(dp, -1, sizeof dp);
	while(scanf("%d", &n) != EOF) {
		ll ans = num_ways(0, n);
		printf(ans > 1 ? "There are %lld ways to produce %d cents change.\n" :
				 "There is only %lld way to produce %d cents change.\n", ans, n);
	}

	return 0;
}

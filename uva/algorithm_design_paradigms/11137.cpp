#include <bits/stdc++.h>

#define MAX 10005

using namespace std;
using ll = long long int;

ll dp[22][MAX];

ll num_ways(int i, int current_change) {
	if(current_change == 0) {
		return 1;
	} else if(current_change < 0 || i == 22) {
		return 0;
	} else if(~dp[i][current_change]) {
		return dp[i][current_change];
	}

	return dp[i][current_change] = num_ways(i, current_change - i * i * i) + num_ways(i + 1, current_change);
}

int main(void) {
	int value;
	memset(dp, -1, sizeof dp);
	while(scanf("%d", &value) != EOF) {
		printf("%lld\n", num_ways(1, value));
	}

	return 0;
}

#include <bits/stdc++.h>

#define MAX 1024
#define MAX_CAP 32

using namespace std;

int n, prices[MAX], weights[MAX], dp[MAX][MAX_CAP];

int knapsack(int item, int current_capacity) {
	if(item > n || current_capacity == 0) {
		return 0;
	} else if(~dp[item][current_capacity]) {
		return dp[item][current_capacity];
	}

	if(current_capacity >= weights[item]) {
		return dp[item][current_capacity] = max(knapsack(item + 1, current_capacity),
							prices[item] + knapsack(item + 1, current_capacity - weights[item]));
	} else {
		return dp[item][current_capacity] = knapsack(item + 1, current_capacity);
	}
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		memset(dp, -1, sizeof dp);
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d %d", &prices[i], &weights[i]);
		}

		int k, ans = 0;
		scanf("%d", &k);
		for(int i = 1; i <= k; ++i) {
			int capacity;
			scanf("%d", &capacity);
			ans += knapsack(1, capacity);
		}

		printf("%d\n", ans);
	}

	return 0;
}

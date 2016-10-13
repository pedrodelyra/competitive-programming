#include <bits/stdc++.h>

#define MAX 32
#define MAX_MONEY 256

using namespace std;

vector<int> garments[MAX];
int dp[MAX_MONEY][MAX];

int max_amount(int m, int g) {
	if(m < 0) {
		return -INT_MAX;
	} else if(g == 0) {
		return 0;
	} else if(~dp[m][g]) {
		return dp[m][g];
	}

	int result = -INT_MAX;
	for(auto& price : garments[g]) {
		result = max(result, max_amount(m - price, g - 1) + price);
	}

	return dp[m][g] = result;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int m, n, result;
		scanf("%d %d", &m, &n);

		for(int i = 1; i <= n; ++i) {
			int k;
			scanf("%d", &k);

			for(int j = 0; j < k; ++j) {
				int price;
				scanf("%d", &price);
				garments[i].push_back(price);
			}
		}

		memset(dp, -1, sizeof dp);
		result = max_amount(m, n);

		printf(result > 0 ? "%d\n" : "no solution\n", result);

		for(int i = 1; i <= n; ++i)
			garments[i].clear();
	}

	return 0;
}

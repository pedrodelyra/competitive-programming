#include <bits/stdc++.h>

#define MAX 64
#define MAX_COIN 512
#define INF (1 << 30)

using namespace std;
using ii = pair<int, int>;

ii coins[MAX];
int n, amount, dp[MAX_COIN][MAX_COIN];

int min_change(int x, int y) {
	if(x * x + y * y == amount) {
		return 0;
	} else if(x * x + y * y > amount) {
		return INF;
	} else if(~dp[x][y]) {
		return dp[x][y];
	}

	int result = INF;
	for(int i = 0; i < n; ++i) {
		result = min(result, min_change(coins[i].first + x, coins[i].second + y) + 1);
	}

	return dp[x][y] = result;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		memset(dp, -1, sizeof dp);
		scanf("%d %d", &n, &amount);

		for(int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			coins[i] = ii(x, y);
		}

		amount *= amount;

		int ans = min_change(0, 0);
		printf(ans < INF ? "%d\n" : "not possible\n", ans);
	}

	return 0;
}

#include <bits/stdc++.h>

#define MAX 30005
#define INF 0x3f3f3f3f

using namespace std;

int n, coins[128], coin_change[MAX];

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int price;
		scanf("%d %d", &price, &n);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &coins[i]);
		}

		coin_change[0] = 0;
		for(int i = 1; i < MAX; ++i) coin_change[i] = INF;

		for(int i = 1; i <= n; ++i) {
			for(int j = MAX - 1; j >= coins[i]; --j) {
				coin_change[j] = min(coin_change[j], coin_change[j - coins[i]] + 1);
			}
		}

		for(int i = price; i < MAX; ++i) {
			if(coin_change[i] < INF) {
				printf("%d %d\n", i, coin_change[i]);
				break;
			}
		}
	}

	return 0;
}

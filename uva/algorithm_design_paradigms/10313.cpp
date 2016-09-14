#include <bits/stdc++.h>

#define MAX 512
#define MAX_COIN 305

using namespace std;

int price, min_coins, max_coins, x, dp[MAX][MAX][MAX_COIN];

int num_ways(int coin, int change, int num) {
	if(num >= min_coins && change == 0) {
		return 1;
	} else if(change < 0 || coin > MAX_COIN || num > max_coins) {
		return 0;
	} else if(~dp[coin][change][num]) {
		return dp[coin][change][num];
	}

	return dp[coin][change][num] = num_ways(coin + 1, change - coin, num + 1) + num_ways(coin + 1, change, num);
}

int main(void) {
	string input;
	memset(dp, -1, sizeof dp);
	while(getline(cin, input)) {
		stringstream ss(input);
		vector<int> v;
		while(ss >> x) v.push_back(x);

		switch(v.size()) {
			case 1:
				price = v[0], max_coins = MAX_COIN;
				printf("%d\n", num_ways(1, price, 0));
				break;
			case 2:
				price = v[0], max_coins = v[1];
				printf("%d\n", num_ways(1, price, 0));
				break;
			case 3:
				int ans = 0;
				for(int i = v[1]; i <= v[2]; ++i) {
					max_coins = i;
					ans += num_ways(1, price, 0);
				}
				printf("%d\n", ans);
				break;
		}
	}

	return 0;
}

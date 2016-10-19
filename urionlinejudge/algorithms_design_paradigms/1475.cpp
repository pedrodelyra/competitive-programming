#include <bits/stdc++.h>

#define MAX 1024
#define oo  0x2f2f2f2f

using namespace std;

int n, c, t1, t2, holes[MAX], dp[MAX];

int min_cost(int i) {
	if(i == 0) {
		return 0;
	} else if(~dp[i]) {
		return dp[i];
	} else {
		int x;
		if((c + holes[i] - holes[1]) % c <= t1) {
			x = t1;
		} else {
			int j = i - 1;
			while(j >= 1 and (c + holes[i] - holes[j]) % c <= t1) --j;
			x = min_cost(j) + t1;
		}
		int y;
		if((c + holes[i] - holes[1]) % c <= t2) {
			y = t2;
		} else {
			int j = i - 1;
			while(j >= 1 and (c + holes[i] - holes[j]) % c <= t2) --j;
			y = min_cost(j) + t2;
		}
		return dp[i] = min(x, y);
	}
}

int main(void) {
	while(~scanf("%d %d %d %d", &n, &c, &t1, &t2)) {
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &holes[i]);
		}

		int ans = oo;
		for(int i = 1; i <= n; ++i) {
			memset(dp, -1, sizeof dp);
			ans = min(ans, min_cost(n));
			rotate(holes + 1, holes + 2, holes + n + 1); 
		}
		printf("%d\n", ans);
	}
	return 0;
}

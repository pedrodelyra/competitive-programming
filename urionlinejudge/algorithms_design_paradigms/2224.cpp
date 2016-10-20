#include <bits/stdc++.h>

#define oo  1e9
#define MAX 16
#define x   first
#define y   second

using namespace std;
using ii  = pair<int, int>;
using vii = vector<ii>;

int n, visited[1 << MAX]; double dp[1 << MAX];
vii points(MAX);

double solve(int mask) {
	if((1 << n) - 1 == mask) {
		return 0;
	} else if(visited[mask]) {
		return dp[mask];
	} else {
		double ans = oo;
		for(int i = 0; i < n; ++i) {
			if((mask >> i) & 1) continue;
			for(int j = i + 1; j < n; ++j) {
				if((mask >> j) & 1) continue;
				ans = min(ans, solve(mask | (1 << i) | (1 << j)) + hypot(points[i].x - points[j].x, points[i].y - points[j].y));
			}
		}
		return visited[mask] = true, dp[mask] = ans;
	}
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			points[i] = ii(a, b);
		}
		memset(visited, false, sizeof visited);
		printf("%.2lf\n", solve(0));
	}
	return 0;
}

#include <bits/stdc++.h>

#define MAX 5005
#define oo  0x3f3f3f3f

using namespace std;
using ii = pair<int, int>;

vector<ii> graph[MAX];
map<ii, ii> parents;
stack<int> path;
int n, max_time, dp[MAX][MAX];

int solve(int u, int t) {
	if(t < 0) {
		return oo;
	} else if(u == 1 and t == 0) {
		return 0;
	} else if(~dp[u][t]) {
		return dp[u][t];
	}
	int min_dist = oo;
	for(auto& edge : graph[u]) {
		int w = edge.first, v = edge.second, curr_dist = solve(v, t - 1);
		if(curr_dist + (long long) w <= max_time and min_dist > curr_dist + (long long) w) {
			parents[ii(u, t)] = ii(v, t - 1);
			min_dist = curr_dist + w;
		}
	}
	return dp[u][t] = min_dist;
}

void print_path(int u, int t) {
	if(u == 1) {
		printf("%d", u);
	} else {
		print_path(parents[ii(u, t)].first, parents[ii(u, t)].second);
		printf(" %d", u);
	}
}

int main(void) {
	int m, t;
	scanf("%d %d %d", &n, &m, &max_time);
	for(int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[v].push_back(ii(w, u));
	}
	memset(dp, -1, sizeof dp);
	for(t = n; solve(n, t) == oo and t >= 2; --t);
	printf("%d\n", t + 1);
	print_path(n, t);
	printf("\n");
	return 0;
}

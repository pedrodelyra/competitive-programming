#include <bits/stdc++.h>

#define MAX 100005

using namespace std;
using ii = pair<int, int>;

vector<ii> tree[MAX];
int total_dist, friends_found, furthest_friend, has_friend[MAX];

void dfs(int u, int dist) {
	if(has_friend[u]) {
		friends_found++;
		furthest_friend = max(furthest_friend, dist);
	}
	for(auto& edge : tree[u]) {
		int v = edge.first, w = edge.second, current_friends = friends_found;
		dfs(v, dist + w);
		if(friends_found > current_friends) {
			total_dist += w;
		}
	}
}

int main(void) {
	int n, k, root = 1;
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		tree[u].push_back(ii(v, w));
	}
	for(int i = 0; i < k; ++i) {
		int u;
		scanf("%d", &u);
		has_friend[u] = true;
	}
	dfs(root, 0);
	printf("%d\n", total_dist - furthest_friend);
	return 0;
}

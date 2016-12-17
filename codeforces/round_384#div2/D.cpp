#include <bits/stdc++.h>

#define MAX 200005
#define oo (1LL << 50)

using namespace std;
using lld = long long int;

vector<int> tree[MAX];
int visited[MAX];
lld a[MAX], s[MAX], best = -oo;

lld dfs1(int u) {
	lld sum = 0;
	visited[u] = true;
	for(auto& v : tree[u]) {
		if(not visited[v]) {
			sum += dfs1(v);
		}
	}
	return s[u] = sum + a[u];
}

lld dfs2(int u) {
	lld x = -oo << 1, y = -oo << 1;
	visited[u] = true;
	for(auto& v : tree[u]) {
		if(not visited[v]) {
			lld k = dfs2(v);
			if(k >= x) {
				y = x;
				x = k;
			} else if(k > y) {
				y = k;
			}
		}
	}
	best = max(best, x + y);
	return max(s[u], max(x, y));
}

int main(void) {
	int n, root = 1;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	memset(visited, false, sizeof visited), dfs1(root);
	memset(visited, false, sizeof visited), dfs2(root);
	printf(best == -oo ? "Impossible\n" : "%lld\n", best);
	return 0;
}

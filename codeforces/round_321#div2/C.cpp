#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

vector<int> tree[MAX];
int k, ans, cats[MAX], visited[MAX];

void dfs(int u, int x) {
	visited[u] = true;
	if(x <= k) {
		int children = 0;
		for(auto& v : tree[u]) {
			if(not visited[v]) {
				dfs(v, cats[u] * x + cats[v]);
				++children;
			}
		}
		if(children == 0) ++ans;
	}
}

int main(void) {
	int n, root = 1;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &cats[i]);
	}
	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(root, cats[root]);
	printf("%d\n", ans);
	return 0;
}

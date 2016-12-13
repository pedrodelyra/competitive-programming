#include <bits/stdc++.h>

#define MAX 100005

using namespace std;
using lld = long long int;

vector<int> tree[MAX];
int cc_size, visited[MAX];

void dfs(int u) {
	visited[u] = true;
	for(auto& v : tree[u]) {
		if(not visited[v]) {
			dfs(v);
		}
	}
	cc_size++;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v, t;
		scanf("%d %d %d", &u, &v, &t);
		if(t == 0) {
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
	}
	vector<int> ccs;
	for(int u = 1; u <= n; ++u) {
		if(not visited[u]) {
			cc_size = 0;
			dfs(u);
			ccs.push_back(cc_size);
		}
	}
	lld ans = 0, sum = 0;
	for(int i = 0; i < ccs.size(); ++i) {
		ans += ccs[i] * (lld) max(n - ccs[i] - sum, 0LL);
		sum += ccs[i];
	}
	printf("%lld\n", ans);
	return 0;
}

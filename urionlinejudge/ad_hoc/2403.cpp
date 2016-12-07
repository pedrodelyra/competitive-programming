#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> in_degree(n, 0), graph[n];
	for(int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		in_degree[v]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int u = 0; u < n; ++u) {
		if(in_degree[u] == 0) {
			pq.push(u);
		}
	}
	vector<int> ans;
	while(not pq.empty()) {
		auto u = pq.top(); pq.pop();
		for(auto& v : graph[u]) {
			if(--in_degree[v] == 0) {
				pq.push(v);
			}
		}
		ans.push_back(u);
	}
	if(ans.size() == n) {
		for(auto& u : ans) {
			printf("%d\n", u);
		}
	} else {
		printf("*\n");
	}
	return 0;
}

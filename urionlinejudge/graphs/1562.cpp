#include <bits/stdc++.h>

#define MAX 10005

using namespace std;
using ii = pair<int, int>;

int graph[MAX], in_degree[MAX], match[MAX];

int main(void) {
	int n;
	while(~scanf("%d", &n)) {
		int count = 0;
		memset(in_degree, 0, sizeof in_degree);
		for(int u = 1; u <= n; ++u) {
			int v;
			scanf("%d", &v);
			graph[u] = v;
			in_degree[v]++;
		}
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		for(int u = 1; u <= n; ++u) {
			pq.push(ii(in_degree[u], u));
		}
		memset(match, -1, sizeof match);
		while(not pq.empty()) {
			int u = pq.top().second; pq.pop();
			int v = graph[u];
			if(!~match[u] and !~match[v]) {
				match[u] = v;
				match[v] = u;
				in_degree[graph[v]]--;
				if(!~match[graph[v]]) {
					pq.push(ii(in_degree[graph[v]], graph[v]));
				}
				count += 2;
			}
		}
		if(count == n) {
			for(int i = 1; i <= n; ++i) {
				if(i > 1) printf(" ");
				printf("%d", match[i]);
			}
			printf("\n");
		} else {
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}

#include <bits/stdc++.h>

#define MAX 256

using namespace std;

vector<int> graph[MAX];
map<string, int> tshirt_id {{"XS", 1}, {"S", 2}, {"M", 3}, {"L", 4}, {"XL", 5}, {"XXL", 6}};
map<string, int> tshirt_count;
int visited[MAX], match[MAX];

int mcbm(int u) {
	if(not visited[u]) {
		visited[u] = true;
		for(auto& v : graph[u]) {
			if(!~match[v] || mcbm(match[v])) {
				match[v] = u;
				return 1;
			}
		}
	}

	return 0;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, m;
		scanf("%d %d", &m, &n);
		for(int u = 1; u <= n; ++u) {
			char A[5], B[5];
			scanf(" %s %s", A, B);
			for(int i = 0; i < m; i += 6) {
				graph[u].push_back(n + i + tshirt_id[A]);
				graph[u].push_back(n + i + tshirt_id[B]);
			}
		}

		int matchings = 0;
		memset(match, -1, sizeof match);
		for(int u = 1; u <= n; ++u) {
			memset(visited, false, sizeof visited);
			matchings += mcbm(u);
		}

		printf(matchings == n ? "YES\n" : "NO\n");

		for(int u = 1; u <= n; ++u)
			graph[u].clear();

		tshirt_count.clear();
	}

	return 0;
}

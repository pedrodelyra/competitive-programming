#include <bits/stdc++.h>

#define MAX 100005

using namespace std;
using ii = pair<int, int>;

vector<int> graph[MAX];
int degrees[MAX], removed[MAX];

int main(void) {
	int n, m, a, b;
	scanf("%d %d %d %d", &n, &m, &a, &b);
	for(int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
		degrees[u]++;
		degrees[v]++;
	}
	set<ii> nodes;
	for(int i = 1; i <= n; ++i) {
		nodes.insert(ii(degrees[i], i));
	}

	ii l = *nodes.begin(), r = *nodes.rbegin();
	while(not nodes.empty()) {
		int x = l.second, y = r.second;

		if(degrees[x] >= a and degrees[y] <= n - b - 1) break;

		if(degrees[x] < a) {
			removed[x] = true;
			for(auto& v : graph[x]) {
				if(not removed[v]) {
					nodes.erase(ii(degrees[v]--, v));
					nodes.insert(ii(degrees[v], v));
				}
			}
			nodes.erase(l);
		}

		if(degrees[y] > n - b - 1) {
			removed[y] = true;
			for(auto& v : graph[y]) {
				if(not removed[v]) {
					nodes.erase(ii(degrees[v]--, v));
					nodes.insert(ii(degrees[v], v));
				}
			}
			nodes.erase(r);
		}

		if(n = nodes.size()) {
			l = *nodes.begin(), r = *nodes.rbegin();
		}
	}
	printf("%d\n", n);
	return 0;
}

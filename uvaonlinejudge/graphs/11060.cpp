#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, m, tc = 0, in_degree[128];
	while(scanf("%d", &n) != EOF) {
		vector<int> graph[128];
		vector<string> beverages(n + 1);
		map<string, int> name_id;
		for(int i = 1; i <= n; ++i) {
			char beverage[128];
			scanf(" %s", beverage);
			name_id[beverage] = i;
			beverages[i] = beverage;
		}

		scanf("%d", &m);
		memset(in_degree, 0, sizeof in_degree);
		for(int i = 0; i < m; ++i) {
			char first_bvrg[128], second_bvrg[128];
			scanf(" %s %s", first_bvrg, second_bvrg);
			int u = name_id[first_bvrg], v = name_id[second_bvrg];
			graph[u].push_back(v);
			in_degree[v]++;
		}

		priority_queue<int, vector<int>, greater<int>> bvrg_list;
		for(int u = 1; u <= n; ++u) {
			if(in_degree[u] == 0)
				bvrg_list.push(u);
		}

		printf("Case #%d: Dilbert should drink beverages in this order:", ++tc);
		while(not bvrg_list.empty()) {
			int u = bvrg_list.top();
			bvrg_list.pop();
			printf(" %s", beverages[u].c_str());
			for(auto& v : graph[u]) {
				if(--in_degree[v] == 0) {
					bvrg_list.push(v);
				}
			}
		}

		printf(".\n\n");
	}

	return 0;
}

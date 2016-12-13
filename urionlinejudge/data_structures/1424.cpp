#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> indexes;

int main(void) {
	int n, m;
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			indexes[x].push_back(i);
		}
		for(int i = 1; i <= m; ++i) {
			int k, v;
			scanf("%d %d", &k, &v);
			printf("%d\n", indexes[v].size() >= k ? indexes[v][k - 1] : 0);
		}
		indexes.clear();
	}
	return 0;
}

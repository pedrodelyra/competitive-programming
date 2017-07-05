#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n;
	while(scanf("%d", &n), n) {
		map<string, int> in_degree, out_degree;
		int max_in = 0, max_out = 0;
		for(int i = 1; i <= n; ++i) {
			char u[32], v[32];
			scanf(" %s -> %s", u, v);
			max_in  = max( max_in,  ++in_degree[v]);
			max_out = max(max_out, ++out_degree[u]);
		}
		printf(max_out == 1 ? (max_in == 1 ? "Invertible.\n" : "Not invertible.\n") : "Not a function.\n");
	}
	return 0;
}

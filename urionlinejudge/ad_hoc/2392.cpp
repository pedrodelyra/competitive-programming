#include <bits/stdc++.h>

using namespace std;

int mark[128];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int j, k;
		scanf("%d %d", &j, &k);
		for(int u = j; u <= n; u += k) mark[u] = true;
		for(int u = j; u >= 0; u -= k) mark[u] = true;
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d\n", mark[i]);
	}
	return 0;
}

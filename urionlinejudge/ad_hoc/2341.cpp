#include <bits/stdc++.h>

using namespace std;

int f[1024];

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		f[x]++;
	}
	int ans = 1 << 30;
	for(int i = 1; i <= k; ++i) {
		ans = min(ans, f[i]);
	}
	printf("%d\n", ans);
	return 0;
}

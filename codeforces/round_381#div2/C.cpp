#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, m, k = 1 << 30;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		k = min(k, r - l + 1); 
	}
	printf("%d\n", k);
	for(int i = 0; i < n; ++i) {
		printf("%d ", i % k);
	}
	printf("\n");
	return 0;
}

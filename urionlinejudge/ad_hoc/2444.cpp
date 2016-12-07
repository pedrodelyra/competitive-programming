#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= k; ++i) {
		int x;
		scanf("%d", &x);
		n += x;
		n = max(n, 0);
		n = min(n, 100);
	}
	printf("%d\n", n);
	return 0;
}

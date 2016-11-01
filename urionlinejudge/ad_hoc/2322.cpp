#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	int ans = n;
	for(int i = 1; i < n; ++i) {
		int x;
		scanf("%d", &x);
		ans ^= x ^ i;
	}
	printf("%d\n", ans);
	return 0;
}

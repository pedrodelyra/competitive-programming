#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, maxv = 0, minv = 1 << 30, A[105];
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);
		maxv = max(maxv, A[i]);
		minv = min(minv, A[i]);
	}
	int x = 0, y = 0;
	for(int i = 1; (!x || !y) && i <= n; ++i) {
		if(!x and A[i] == maxv) {
			x = i;
		}
		if(!y and A[n - i + 1] == minv) {
			y = n - i + 1;
		}
	}
	printf("%d\n", x - 1 + n - y - (x > y));
	return 0;
}

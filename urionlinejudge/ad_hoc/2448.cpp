#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int dist = 0;
	for(int i = 1, j = 1; i <= m; ++i) {
		int x;
		scanf("%d", &x);
		int l = 1, r = n, k = -1;
		while(!~k and l <= r) {
			int m = l + r >> 1;
			if(a[m] == x) {
				k = m;
			} else if(a[m] < x) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		dist += abs(j - k);
		j = k;
	}
	printf("%d\n", dist);
	return 0;
}

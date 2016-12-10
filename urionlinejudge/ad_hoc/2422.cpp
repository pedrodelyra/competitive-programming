#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int x = -1, y = -1, k;
	scanf("%d", &k);
	for(int i = 1; !~x and !~y and i < n; ++i) {
		int l = i, r = n;
		while(l <= r) {
			int j = l + r >> 1;
			if(a[i] + a[j] == k) {
				x = a[i], y = a[j];
				break;
			} else if(a[i] + a[j] < k) {
				l = j + 1;
			} else {
				r = j - 1;
			}
		}
	}
	printf("%d %d\n", x, y);
	return 0;
}

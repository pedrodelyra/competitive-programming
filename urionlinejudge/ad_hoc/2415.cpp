#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> a(n + 1, 0);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int ans = 0, count = 1;
	for(int i = 1; i <= n; ++i) {
		if(a[i] == a[i - 1]) {
			ans = max(ans, ++count);
		} else {
			count = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}

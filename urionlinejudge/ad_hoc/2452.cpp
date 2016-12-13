#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(m + 1);
	for(int i = 1; i <= m; ++i) {
		scanf("%d", &a[i]);
	}
	int days = max(a[1] - 1, n - a[m]);
	for(int i = 2; i <= m; ++i) {
		days = max(days, (a[i] - a[i - 1]) >> 1);
	}
	printf("%d\n", days);
	return 0;
}

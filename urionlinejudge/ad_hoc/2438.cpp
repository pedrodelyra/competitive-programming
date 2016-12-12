#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

int main(void) {
	int n;
	scanf("%d", &n);
	lld sum = 0, f[8] = {1, 0, 0, 0, 0, 0, 0, 0};
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		f[sum = (sum + x) % 8]++;
	}
	lld ans = 0;
	for(int i = 0; i < 8; ++i) {
		ans += f[i] * (f[i] - 1) >> 1;
	}
	printf("%lld\n", ans);
	return 0;
}

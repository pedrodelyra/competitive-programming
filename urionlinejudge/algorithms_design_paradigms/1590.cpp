#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, k, ans = 0;
		scanf("%d %d", &n, &k);
		vector<int> a(n + 1);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		bool forbidden[40] = {false};
		for(int mask = 1 << 30; mask >= 1; mask >>= 1) {
			int x = -1, count = 0, t = 0, b[n + 1];
			for(int j = 1; j <= n; ++j) {
				if(forbidden[j]) continue;

				if(a[j] & mask) {
					x &= a[j];
					++count;
				} else {
					b[++t] = j;
				}
			}
			if(count >= k) {
				for(int j = 1; j <= t; ++j) {
					forbidden[b[j]] = true;
				}
				ans = max(ans, x);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

#include <bits/stdc++.h>

#define oo (1 << 30)

using namespace std;

int main(void) {
	int n, ans, best = oo;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int m;
		scanf("%d", &m);

		int H[m + 1];
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &H[j]);
		}

		int gap_from_left = 0, gap_from_right = 0;
		for(int j = 2; j <= m; ++j) {
			gap_from_left  += max(H[j] - H[j - 1], 0);
			gap_from_right += max(H[m - j + 1] - H[m - j + 2], 0);
		}

		if(best > min(gap_from_left, gap_from_right)) {
			best = min(gap_from_left, gap_from_right);
			ans  = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}

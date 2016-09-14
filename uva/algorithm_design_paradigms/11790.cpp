#include <bits/stdc++.h>

#define MAX 2048

using namespace std;

int heights[MAX], lengths[MAX];

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &heights[i]);
		}

		for(int i = 0; i < n; ++i) {
			scanf("%d", &lengths[i]);
		}

		int lis[n], lds[n], max_lis = 0, max_lds = 0;
		for(int i = 0; i < n; ++i) {
			lis[i] = lds[i] = lengths[i];
			for(int j = 0; j < i; ++j) {
				if(heights[i] > heights[j]) {
					lis[i] = max(lis[i], lis[j] + lengths[i]);
				}

				if(heights[i] < heights[j]) {
					lds[i] = max(lds[i], lds[j] + lengths[i]);
				}
			}

			max_lis = max(max_lis, lis[i]);
			max_lds = max(max_lds, lds[i]);
		}

		if(max_lis >= max_lds) {
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", tc, max_lis, max_lds);
		} else {
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", tc, max_lds, max_lis);
		}
	}

	return 0;
}

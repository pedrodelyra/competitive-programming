#include <bits/stdc++.h>

int main(void) {
	int tests;
	scanf("%d", &tests);
	for(int tc = 1; tc <= tests; ++tc) {
		int n;
		scanf("%d", &n);

		int sum = 0, max_sum = 0, start = 0, end = -1;
		for(int i = 1, j = 1; j < n; ++j) {
			int x;
			scanf("%d", &x);
			sum += x;

			if(max_sum < sum || (max_sum == sum && j - i > end - start)) {
				start = i;
				end = j;
				max_sum = sum;
			}

			if(sum < 0) {
				i = j + 1;
				sum = 0;
			}
		}

		if(max_sum > 0) {
			printf("The nicest part of route %d is between stops %d and %d\n", tc, start, end + 1);
		} else {
			printf("Route %d has no nice parts\n", tc);
		}
	}

	return 0;
}

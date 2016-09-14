#include <cstdio>
#include <algorithm>

#define MAX 1024
#define INF (1 << 30)

int array[MAX];

int main(void) {
	int n, tc = 0;
	while(scanf("%d", &n), n) {
		for(int i = 0; i < n; ++i)
			scanf("%d", &array[i]);

		int q;
		scanf("%d", &q);
		printf("Case %d:\n", ++tc);
		while(q--) {
			int sum, closest_sum = INF;
			scanf("%d", &sum);
			for(int i = 0; i < n; ++i) {
				for(int j = i + 1; j < n; ++j) {
					int current_sum = array[i] + array[j];
					if(abs(current_sum - sum) < abs(closest_sum - sum)) {
						closest_sum = current_sum;
					}
				}
			}

			printf("Closest sum to %d is %d.\n", sum, closest_sum);
		}

	}

	return 0;
}

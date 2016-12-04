#include <cstdio>

int main(void) {
	int n, total_dist = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int v, t;
		scanf("%d %d", &v, &t);
		total_dist += v * t;
	}
	printf("%d\n", total_dist);
	return 0;
}

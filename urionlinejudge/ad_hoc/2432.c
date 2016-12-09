#include <stdio.h>
#include <math.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

typedef long long int lld;

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	lld i, radius[n + 1];
	for(i = 1; i <= n; ++i) {
		scanf("%lld", &radius[i]);
		radius[i] *= radius[i];
	}
	lld hits = 0;
	for(i = 1; i <= m; ++i) {
		lld x, y;
		scanf("%lld %lld", &x, &y);
		lld squared_dist = x * x + y * y;
		unsigned j = -1, l = 1, r = n;
		while(l <= r) {
			int mid = l + r >> 1;
			if(squared_dist <= radius[mid]) {
				j = min(j, mid);
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if(~j) hits += n - j + 1;
	}
	printf("%lld\n", hits);
	return 0;
}

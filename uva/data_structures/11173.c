#include <stdio.h>

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, k;
		scanf("%d %d", &n, &k);
		printf("%d\n", k ^ (k >> 1));
	}

	return 0;
}

#include <stdio.h>

int main(void) {
	int i, n, A[105] = {0};
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);
	}
	for(i = 1; i <= n; ++i) {
		printf("%d\n", A[i - 1] + A[i] + A[i + 1]);
	}
	return 0;
}

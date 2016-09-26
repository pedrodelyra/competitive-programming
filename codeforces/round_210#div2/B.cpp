#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

int A[MAX];

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);

	if(n == k) {
		printf("-1\n");
	} else {
		A[1] = k + 2 > n ? 1 : k + 2, A[n] = 1;

		for(int i = 2; i <= k + 1; ++i) {
			A[i] = i;
		}

		for(int i = k + 2; i < n; ++i) {
			A[i] = i + 1;
		}

		for(int i = 1; i <= n; ++i) {
			printf("%d ", A[i]);
		}
		printf("\n");
	}

	return 0;
}

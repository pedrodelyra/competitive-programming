#include <bits/stdc++.h>

using namespace std;

int A[10005];

int main(void) {
	int n, k, max_size = 0;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; ++i) {
		scanf("%d", &A[i]);
		max_size = max(max_size, A[i]);
	}
	int ans = -1;
	for(int j = max_size; !~ans && j >= 1; --j) {
		int sum = 0;
		for(int i = 0; i < k; ++i) {
			sum += A[i] / j;
		}
		if(sum >= n) ans = j;
	}
	printf("%d\n", ans);
	return 0;
}

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
	int ans, low = 0, high = max_size;
	while(low <= high) {
		int mid = (low + high) >> 1, sum = 0;
		for(int i = 0; i < k; ++i) {
			sum += A[i] / mid;
		}
		if(sum < n) {
			high = mid - 1;
		} else if(sum >= n) {
			ans = mid;
			low = mid + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}

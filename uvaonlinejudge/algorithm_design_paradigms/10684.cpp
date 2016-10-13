#include <bits/stdc++.h>

using namespace std;

int kadane(int* A, int n) {
	int sum = 0, ans = 0;
	for(int i = 0; i < n; ++i) {
		sum += A[i];
		ans = max(ans, sum);
		sum = max(sum, 0);
	}

	return ans;
}

int main(void) {
	int n;
	while(scanf("%d", &n), n) {
		int A[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &A[i]);
		}

		int sol = kadane(A, n);
		printf(sol > 0 ? "The maximum winning streak is %d.\n" : "Losing streak.\n", sol);
	}

	return 0;
}

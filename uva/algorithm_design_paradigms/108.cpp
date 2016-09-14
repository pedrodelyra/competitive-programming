#include <bits/stdc++.h>

using namespace std;

int kadane(int* A, int n) {
	int sum = 0, max_sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += A[i];
		max_sum = max(max_sum, sum);
		sum = max(sum, 0);
	}

	return max_sum;
}

int main(void) {
	int n, A[128][128];
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			scanf("%d", &A[i][j]);
		}
	}

	int sol = -INT_MAX;
	for(int i = 0; i < n; ++i) {
		int tmp[n] = {0};
		for(int j = i; j < n; ++j) {
			for(int k = 0; k < n; ++k)
				tmp[k] += A[k][j];

			int sum = kadane(tmp, n);
			sol = max(sol, sum);
		}
	}

	printf("%d\n", sol);

	return 0;
}

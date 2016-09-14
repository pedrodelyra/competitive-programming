#include <bits/stdc++.h>

#define MAX 2048

using namespace std;

int A[MAX];

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n;
		scanf("%d\n", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &A[i]);
		}

		int lis[MAX], lds[MAX], ans = 0;
		for(int i = n - 1; i >= 0; --i) {
			lis[i] = lds[i] = 1;
			for(int j = i + 1; j < n; ++j) {
				if(A[i] > A[j]) {
					lis[i] = max(lis[i], lis[j] + 1);
				}

				if(A[i] < A[j]) {
					lds[i] = max(lds[i], lds[j] + 1);
				}
			}

			ans = max(ans, lis[i] + lds[i] - 1);
		}

		printf("%d\n", ans);
	}

	return 0;
}

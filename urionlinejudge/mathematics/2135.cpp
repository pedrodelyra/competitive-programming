#include <bits/stdc++.h>

#define oo (1 << 30)

using namespace std;

int main(void) {
	int n, tc = 0;
	while(~scanf("%d", &n)) {
		vector<int> A(n + 1), sum(n + 1, 0);
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &A[i]);
			sum[i] = sum[i - 1] + A[i];
		}

		int ans = oo;
		for(int i = 1; ans == oo and i <= n; ++i) {
			if(A[i] == sum[i - 1]) {
				ans = A[i];
			}
		}

		printf("Instancia %d\n", ++tc);
		printf(ans != oo ? "%d\n\n" : "nao achei\n\n", ans);
	}
	return 0;
}

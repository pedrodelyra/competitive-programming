#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n;
	while(scanf("%d", &n), n) {
		long long x = 0, A[n];
		for(int i = 0; i < n; ++i) {
			scanf("%lld", &A[i]);
			x ^= A[i];
		}

		long long a = 0, b = 0, lsb = x & -x;
		for(int i = 0; i < n; ++i) {
			if(A[i] & lsb) {
				a ^= A[i];
			} else {
				b ^= A[i];
			}
		}

		printf("%lld %lld\n", min(a, b), max(a, b));
	}
	return 0;
}

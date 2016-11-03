#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, sum = 0, odd = 0, A[128];
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);
		sum += A[i];
		odd += A[i] & 1;
	}
	printf("%d\n", sum & 1 ? odd : n - odd);
	return 0;
}

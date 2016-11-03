#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, k = 1;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			printf("%d ", j & 1 ? k : n * n - k++ + 1);
		}
		printf("\n");
	}
	return 0;
}

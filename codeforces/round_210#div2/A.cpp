#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			printf("%d ", i == j ? k : 0);
		}
		printf("\n");
	}

	return 0;
}

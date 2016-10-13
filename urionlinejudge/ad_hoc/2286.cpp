#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, tc = 0;
	while(scanf("%d", &n), n) {
		char A[32], B[32];
		scanf(" %s %s", A, B);
		printf("Teste %d\n", ++tc);
		for(int i = 1; i <= n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%s\n", (x + y) & 1 ? B : A);
		}
		printf("\n");
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, tc = 0;
	while(scanf("%d", &n), n) {
		int a = 0, b = 0;
		printf("Teste %d\n", ++tc);
		for(int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			a += x, b += y;
			printf("%d\n", a - b);
		}
		printf("\n");
	}
	return 0;
}

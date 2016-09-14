#include <cstdio>

int main(void) {
	int n, tc = 0;
	while(scanf("%d", &n), n) {
		int ans;
		for(int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			if(x == i) ans = x;
		}

		printf("Teste %d\n%d\n\n", ++tc, ans);
	}

	return 0;
}

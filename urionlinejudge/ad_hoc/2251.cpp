#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, tc = 0;
	while(scanf("%d", &n), n) {
		printf("Teste %d\n%d\n\n", ++tc, (1 << n) - 1);
	}
	return 0;
}

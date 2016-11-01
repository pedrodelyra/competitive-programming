#include <bits/stdc++.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int ans, x = n - 10;
	if(x <= 0 || x > 11) {
		ans = 0;
	} else if(x == 10) {
		ans = 15;
	} else {
		ans = 4;
	}
	printf("%d\n", ans);
	return 0;
}

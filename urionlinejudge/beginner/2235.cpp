#include <bits/stdc++.h>

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	bool ans = (a == b + c) || (b == a + c) || (c == a + b) || (a == b) || (a == c) || (b == c);
	printf(ans ? "S\n" : "N\n");
	return 0;
}

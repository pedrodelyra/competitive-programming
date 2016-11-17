#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d\n", max(a + d, b + c) - min(a + d, b + c));
	return 0;
}

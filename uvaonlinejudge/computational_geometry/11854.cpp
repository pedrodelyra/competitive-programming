#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c), a | b | c) {
		int x = max(a, max(b, c)), y = min(a, min(b, c)), z = max(min(a, b), min(max(a, b), c));
		printf(x * x == y * y + z * z ? "right\n" : "wrong\n");
	}

	return 0;
}

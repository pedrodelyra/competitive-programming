#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	int a = max(x1, x3), b = min(x2, x4), c = max(y1, y3), d = min(y2, y4);
	printf("%d\n", a <= b and c <= d);
	return 0;
}

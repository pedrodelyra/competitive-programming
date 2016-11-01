#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, x, y;
	for(int i = 1; i <= 5; ++i) {
		for(int j = 1; j <= 5; ++j) {
			scanf("%d", &n);
			if(n) {
				x = i, y = j;
			}
		}
	}
	printf("%d\n", abs(x - 3) + abs(y - 3));
	return 0;
}

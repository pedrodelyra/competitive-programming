#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, sum = 0;;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		sum += x - 1;
	}
	printf("%d\n", sum);
	return 0;
}

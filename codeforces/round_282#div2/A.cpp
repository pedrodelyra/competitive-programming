#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, count[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
	scanf("%d", &n);
	printf("%d\n", count[n % 10] * count[n / 10]);
	return 0;
}

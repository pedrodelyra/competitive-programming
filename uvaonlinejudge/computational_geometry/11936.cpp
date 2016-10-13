#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	while(n--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf(a < b + c and b < a + c and c < a + b ? "OK\n" : "Wrong!!\n");
	}
	return 0;
}

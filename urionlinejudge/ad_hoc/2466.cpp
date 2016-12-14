#include <bits/stdc++.h>

#define BLACK  1
#define WHITE -1

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	int a[n + 1][n + 1];
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[n][i]);
	}
	for(int i = n - 1; i >= 1; --i) {
		for(int j = 1; j <= i; ++j) {
			if(a[i + 1][j] == a[i + 1][j + 1]) {
				a[i][j] = BLACK;
			} else {
				a[i][j] = WHITE;
			}
		}
	}
	printf(~a[1][1] ? "preta\n" : "branca\n");
	return 0;
}

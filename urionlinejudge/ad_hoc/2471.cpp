#include <bits/stdc++.h>

#define MAX 64

using namespace std;

int a[MAX][MAX], rows[MAX], cols[MAX], f[500005];

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	int sum = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			rows[i] += a[i][j];
			cols[i] += a[j][i];
		}
		if(++f[rows[i]] >= 2) sum = rows[i];
	}
	int x, y;
	for(int i = 1; i <= n; ++i) {
		if(rows[i] != sum) x = i;
		if(cols[i] != sum) y = i;
	}
	printf("%d %d\n", a[x][y] + sum - rows[x], a[x][y]);
	return 0;
}

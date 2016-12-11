#include <bits/stdc++.h>

using namespace std;

int primary_diagonal, counter_diagonal, rows[1024], cols[1024], f[1024 * 1024], a[1024][1024];

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
			if(a[i][j] <= n * n) {
				f[a[i][j]] = 1;
			}
		}
	}
	int m = 0, count = 0;
	for(int i = 1; i <= n * n; ++i) {
		count += f[i];
	}
	if(count == n * n) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				rows[i] += a[i][j];
				cols[i] += a[j][i];
			}
		}
		for(int i = 1; i <= n; ++i) {
			primary_diagonal += a[i][i];
			counter_diagonal += a[i][n - i + 1];
		}
		m = primary_diagonal == counter_diagonal;
		for(int i = 1; i <= n; ++i) {
			if(rows[i] == cols[i]) {
				++m;
			}
		}
	}
	printf("%d\n", m == n + 1 ? primary_diagonal : 0);
	return 0;
}

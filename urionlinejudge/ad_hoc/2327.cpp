#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, A[15][15];
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &A[i][j]);
		}
	}
	vector<int> sum;
	for(int i = 1; i <= n; ++i) {
		int row = 0, col = 0;
		for(int j = 1; j <= n; ++j) {
			row += A[i][j];
			col += A[j][i];
		}
		sum.push_back(row);
		sum.push_back(col);
	}
	int primary_diagonal = 0, secondary_diagonal = 0;
	for(int i = 1; i <= n; ++i) {
		primary_diagonal += A[i][i];
		secondary_diagonal += A[i][n - i + 1];
	}
	sum.push_back(primary_diagonal);
	sum.push_back(secondary_diagonal);
	int ans = sum[0];
	for(int i = 0; ~ans and i < sum.size(); ++i) {
		if(sum[i] != ans) ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}

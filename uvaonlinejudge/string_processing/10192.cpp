#include <bits/stdc++.h>

#define MAX 128

using namespace std;

string A, B;

int main(void) {
	int tc = 0;
	while(getline(cin, A), A[0] != '#') {
		getline(cin, B);

		int i, j, n = A.size(), m = B.size(), lcs[MAX][MAX];
		for(i = 0; i <= n; ++i) {
			for(j = 0; j <= m; ++j) {
				if(i == 0 || j == 0) {
					lcs[i][j] = 0;
				} else if(A[i - 1] == B[j - 1]) {
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				} else {
					lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
				}
			}
		}

		printf("Case #%d: you can visit at most %d cities.\n", ++tc, lcs[n][m]);
	}

	return 0;
}

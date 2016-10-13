#include <bits/stdc++.h>

#define MAX 128
#define INSERT 1
#define DELETE 2
#define REPLACE 3

using namespace std;

string A, B;

int main(void) {
	int tc = 0;
	while(getline(cin, A)) {
		getline(cin, B);
		int n = A.size(), m = B.size(), edit_dist[MAX][MAX];
		for(int i = 0; i <= n; ++i) {
			for(int j = 0; j <= m; ++j) {
				if(i == 0 || j == 0) {
					edit_dist[i][j] = max(i, j);
				} else if(A[i - 1] == B[j - 1]) {
					edit_dist[i][j] = edit_dist[i - 1][j - 1];
				} else {
					edit_dist[i][j] = 1 + min(edit_dist[i - 1][j - 1], min(edit_dist[i - 1][j], edit_dist[i][j - 1]));
				}
			}
		}

		if(tc++) printf("\n");
		printf("%d\n", edit_dist[n][m]);

		int commands = 0;
		while(n || m) {
			if(A[n - 1] == B[m - 1]) {
				--n, --m;
				continue;
			}

			printf("%d ", ++commands);

			if(n && edit_dist[n][m] == edit_dist[n - 1][m] + 1) {
				printf("Delete %d\n", n);
				A.erase(n - 1, 1);
				--n;
			} else if(m && edit_dist[n][m] == edit_dist[n][m - 1] + 1) {
				printf("Insert %d,%c\n", n + 1, B[m - 1]);
				A.insert(n, 1, B[m - 1]);
				--m;
			} else if(n && m) {
				printf("Replace %d,%c\n", n, B[m - 1]);
				A[n - 1] = B[m - 1];
				--n, --m;
			}
		}
	}

	return 0;
}

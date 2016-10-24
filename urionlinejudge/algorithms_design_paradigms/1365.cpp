#include <bits/stdc++.h>

#define MAX 305
#define oo  (1 << 20)

using namespace std;

char grid[MAX][MAX];
int  free_seats[MAX][MAX];

// returns the size of the smallest subinterval of A such that the sum of its elements is equal to k.
int subinterval_sum(int* A, int n, int k) {
    int i = 1, j = 1, current_sum = 0, min_length = oo;  
    while(j <= n) {
        while(current_sum < k && j <= n) {
            current_sum += A[j++];
        }
        while(current_sum >= k) {
            min_length = min(min_length, j - i);
            current_sum -= A[i++];
        }
    } 
    return min_length;
}

int main(void) {
	int n, m, k;
	while(scanf("%d %d %d", &n, &m, &k), n | m | k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				scanf(" %c", &grid[i][j]);
			}
		}

		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				free_seats[i][j] = grid[i][j] ==  '.';
			}
		}

		int ans = oo;
		for(int i = 1; i <= m; ++i) {
			int tmp[n + 1]; memset(tmp, 0, sizeof tmp);
			for(int j = i; j <= m; ++j) {
				for(int k = 1; k <= n; ++k) {
					tmp[k] += free_seats[k][j];
				}
				ans = min(ans, subinterval_sum(tmp, n, k) * (j - i + 1));
			}	
		}
		printf("%d\n", ans);
	}
	return 0;
}

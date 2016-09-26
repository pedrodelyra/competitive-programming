#include <bits/stdc++.h>

#define MAX 300005

using namespace std;

char A[MAX];

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
                char c;
                scanf(" %c", &A[i]);
        }

	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	for(int i = 1; i <= n; ++i) {
		if(i & 1) {
			x1 += A[i] != 'r';
			x2 += A[i] != 'b';
		} else {
			y1 += A[i] != 'b';
			y2 += A[i] != 'r';
		}
	}

	printf("%d\n", min(x1 + y1 - min(x1, y1), x2 + y2 - min(x2, y2)));

	return 0;
}

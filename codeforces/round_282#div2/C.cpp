#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

char A[MAX];

int main(void) {
	scanf("%s", A);
	int count = 0, o = 0, c = 0, k = 0, last = 0;
	for(int i = 0; A[i]; ++i) {
		if(A[i] == '#') k++, last = i;
		if(A[i] == '(') o++;
		if(A[i] == ')') c++;
	}

	for(int i = 0; A[i] and count >= 0; ++i) {
		if(A[i] == '(') {
			++count;
		}

		if(A[i] == ')') {
			--count;
		}

		if(A[i] == '#') {
			if(i != last) {
				--count;
			} else {
				count -= max(1, o - c - k + 1);
			}
		}
	}

	if(count) {
		printf("-1\n");
	} else {
		for(int i = 1; i < k; ++i) {
			printf("1\n");
		}
		printf("%d\n", max(1, o - c - k + 1));
	}

	return 0;
}

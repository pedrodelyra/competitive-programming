#include <bits/stdc++.h>

using namespace std;

int A[1 << 10];

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);
	}
	int count = 0, min_score = A[1], max_score = A[1];
	for(int i = 2; i <= n; ++i) {
		if(A[i] > max_score) {
			max_score = A[i];
			count++;
		}
		if(A[i] < min_score) {
			min_score = A[i];
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}

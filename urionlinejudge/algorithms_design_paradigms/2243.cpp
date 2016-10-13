#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(void) {
	int n;
	scanf("%d", &n);

	vi A(n + 1), X(n + 2, 0), Y(n + 2, 0);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);
	}

	for(int i = 1; i <= n; ++i) X[i] = min(A[i], X[i - 1] + 1);

	for(int i = n; i >= 1; --i) Y[i] = min(A[i], Y[i + 1] + 1);

	int max_height = 1;
	for(int i = 1; i <= n; ++i) {
		max_height = max(max_height, min(X[i], Y[i]));
	}

	printf("%d\n", max_height);

	return 0;
}

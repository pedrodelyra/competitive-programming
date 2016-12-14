#include <bits/stdc++.h>

using namespace std;

int kadane(vector<int>& a) {
	int sum = 0, max_sum = 0, n = a.size() - 1;
	for(int i = 1; i <= n; ++i) {
		max_sum = max(max_sum, sum = max(sum + a[i], 0));
	}
	return max_sum;
}

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", kadane(a));
	return 0;
}

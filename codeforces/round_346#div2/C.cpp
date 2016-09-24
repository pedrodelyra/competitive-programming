#include <bits/stdc++.h>

#define MAX 300005

using namespace std;

set<int> toys;

int main(void) {
	int n, m, sum = 0;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		toys.insert(x);
	}

	vector<int> ans;
	for(int i = 1; i < MAX && sum + i <= m; ++i) {
		if(toys.count(i) == 0) {
			sum += i;
			ans.push_back(i);
		}
	}

	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); ++i) {
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");

	return 0;
}

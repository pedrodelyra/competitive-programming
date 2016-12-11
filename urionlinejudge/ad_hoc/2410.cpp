#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	set<int> s;
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		s.insert(x);
	}
	printf("%d\n", s.size());
	return 0;
}

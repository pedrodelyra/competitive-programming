#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int main(void) {
	int n;
	scanf("%d", &n);
	set<ii> s;
	for(int i = 1; i <= n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		s.insert(ii(x, y));
	}
	printf("%d\n", s.size() < n);
	return 0;
}

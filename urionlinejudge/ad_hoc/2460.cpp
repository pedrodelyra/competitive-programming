#include <bits/stdc++.h>

#define MAX 100005

using namespace std;
using ii = pair<int, int>;

int idx[MAX];

int main(void) {
	int n;
	scanf("%d", &n);
	set<ii> s;
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		s.insert(ii(idx[x] = i, x));
	}
	int m;
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i) {
		int x;
		scanf("%d", &x);
		s.erase(ii(idx[x], x));
	}
	bool print_space = false;
	for(auto& x : s) {
		if(print_space) { printf(" "); } else { print_space = true; }
		printf("%d", x.second);
	}
	printf("\n");
	return 0;
}

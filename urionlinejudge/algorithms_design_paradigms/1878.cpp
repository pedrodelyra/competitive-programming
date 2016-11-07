#include <bits/stdc++.h>

#define MAX 5

using namespace std;
using vi  = vector<int>;
using vvi = vector<vi>;

vi A, c(MAX);
set<vi> s;

void solve(int n, int m) {
	if(A.size() == n) {
		s.insert(A);
	} else {
		for(int i = 1; i <= m; ++i) {
			A.push_back(i);
			solve(n, m);
			A.pop_back();
		}
	}
}

int main(void) {
	int n, m;
	while(~scanf("%d %d", &n, &m)) {
		bool ans = true;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &c[i]);
		}
		solve(n, m);
		vvi combinations(s.begin(), s.end());
		for(int i = 0; ans and i < combinations.size(); ++i) {
			for(int j = i + 1; ans and j < combinations.size(); ++j) {
				int x = 0, y = 0;
				for(int k = 1; k <= n; ++k) {
					x += combinations[i][k - 1] * c[k];
					y += combinations[j][k - 1] * c[k];
				}
				if(x == y) ans = false;
			}
		}
		printf(ans ? "Lucky Denis!\n" : "Try again later, Denis...\n");
		s.clear();
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, m, x;
	scanf("%d %d", &n, &m);
	unordered_set<int> a, b;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &x);
		a.insert(x);
	}
	bool valid_sequence = true;
	for(int i = 1; valid_sequence and i <= m; ++i) {
		scanf("%d", &x);
		valid_sequence = false;
		if((valid_sequence = a.count(x)) == 0) {
			for(auto& y : b) {
				if(b.count(x - y)) {
					valid_sequence = true;
					break;
				}
			}
		}
		if(valid_sequence) b.insert(x);
	}
	printf(valid_sequence ? "sim\n" : "%d\n", x);
	return 0;
}

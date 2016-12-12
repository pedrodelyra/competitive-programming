#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	multiset<int> s;
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		s.insert(x);
	}
	int count = 0;
	for(auto& x : a) {
		int max_soldier = *s.rbegin();
		if(max_soldier <= x) {
			s.erase(s.begin());
		} else {
			++count;
			s.erase(s.upper_bound(x));
		}
	}
	printf("%d\n", count);
	return 0;
}

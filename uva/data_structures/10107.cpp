#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main(void) {
	int i = 1, n;
	while(scanf("%d", &n) != EOF) {
		int mid;
		v.push_back(n);
		mid = v.size() / 2;
		sort(v.begin(), v.end());
		printf("%d\n", i & 1 ? v[mid] : (v[mid] + v[mid - 1]) >> 1);
		i++;
	}

	return 0;
}

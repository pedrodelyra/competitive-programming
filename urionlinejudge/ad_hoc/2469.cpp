#include <bits/stdc++.h>

using namespace std;

map<int, int> frequence;

int main(void) {
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		ans = frequence[ans] == ++frequence[x] ? (ans < x ? x : ans) : (frequence[ans] < frequence[x] ? x : ans);
	}
	printf("%d\n", ans);
	return 0;
}

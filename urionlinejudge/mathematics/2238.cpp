#include <bits/stdc++.h>

using namespace std;

vector<int> divisors;

int main(void) {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	for(int i = 1; i * i <= c; ++i) {
		if(c % i == 0) {
			divisors.push_back(i), divisors.push_back(c / i);
		}
	}
	sort(divisors.begin(), divisors.end());

	int ans = -1;
	for(auto& n : divisors) {
		if(n % a == 0 and n % b and d % n) {
			ans = n;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}

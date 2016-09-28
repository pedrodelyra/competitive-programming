#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);

	if(a == b) {
		printf("infinity\n");
	} else {
		vector<int> divisors;
		int k = a - b;
		for(int i = 1; i * i <= k; ++i) {
			if(k % i == 0) {
				divisors.push_back(i);

				if(i * i < k) divisors.push_back(k / i);
			}
		}

		int ans = 0;
		for(auto& d : divisors) {
			ans += d > b;
		}
		printf("%d\n", ans);
	}

	return 0;
}

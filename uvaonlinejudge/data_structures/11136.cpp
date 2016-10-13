#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
	int n;
	while(scanf("%d", &n), n) {
		multiset<ll> bills;
		ll amount = 0;
		for(int i = 0; i < n; ++i) {
			ll k;
			scanf("%lld", &k);
			for(int j = 0; j < k; ++j) {
				ll bill;
				scanf("%lld", &bill);
				bills.insert(bill);
			}

			ll x = *bills.rbegin(), y = *bills.begin();
			amount += x - y;

			bills.erase(bills.begin());
			bills.erase(--bills.end());
		}

		printf("%lld\n", amount);
	}

	return 0;
}

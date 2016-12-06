#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

bool prime(lld n) {
	for(lld i = 2; i * i <= n; ++i) {
		if(n % i == 0) return false;
	}
	return true;
}

int main(void) {
	lld n;
	scanf("%lld", &n);
	printf(not prime(n) ? "S\n" : "N\n");
	return 0;
}

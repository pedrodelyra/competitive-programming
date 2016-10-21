#include <bits/stdc++.h>

using namespace std;

bool ok(long long x) {
	x = abs(x);
	while(x) {
		if(x % 10 == 8) {
			return true;
		} else {
			x /= 10;
		}
	}
	return false;
}

int main(void) {
	long long x;
	scanf("%lld", &x);
	int count = 1;
	for(long long i = x + 1; not ok(i); ++i, ++count);
	printf("%d\n", count);
	return 0;
}

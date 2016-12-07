#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if(a == 0) {
		return b;
	} else {
		return gcd(b % a, a);
	}
}

int main(void) {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int num = a * d + b * c, div = b * d;
	printf("%d %d\n", num / gcd(num, div), div / gcd(num, div));
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

double f(int n) {
	if(n == 0) {
		return 0;
	} else {
		return 1 / (2 + f(n - 1));
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%.10lf\n", 1 + f(n));
	return 0;
}

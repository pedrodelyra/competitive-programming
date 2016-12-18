#include <bits/stdc++.h>

#define MAX 200005

using namespace std;

char str[MAX];

int main(void) {
	int n, k, a, b;
	scanf("%d %d %d %d", &n, &k, &a, &b);
	int x = 0, green = 0, black = 0, possible = true;
	while(possible and (a > 0 or b > 0)) {
		if(a >= b) {
			if(++green <= k) {
				str[x++] = 'G';
				--a, black = 0;
			} else {
				str[x++] = 'B';
				--b, green = 0;
			}
		} else {
			if(++black <= k) {
				str[x++] = 'B';
				--b, green = 0;
			} else {
				str[x++] = 'G';
				--a, black = 0;
			}
		}
	}
	printf("%s\n", a == 0 and b == 0 ? str : "NO");
	return 0;
}

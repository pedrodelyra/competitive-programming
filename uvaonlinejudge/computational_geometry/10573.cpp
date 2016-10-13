#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		char input[32];
		scanf(" %[^\n]", input);

		int x, y;
		if(sscanf(input, "%d %d", &x, &y) == 1) {
			printf("%.4lf\n", pi * x * x / 8);
		} else {
			printf("%.4lf\n", 2 * pi * x * y);
		}
	}
	return 0;
}

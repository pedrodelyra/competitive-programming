#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int w, h, r1, r2;
	while(scanf("%d %d %d %d", &w, &h, &r1, &r2), w | h | r1 | r2) {
		int sum = r1 + r2, d1 = r1 << 1, d2 = r2 << 1;
		printf(max(d1, d2) <= w and max(d1, d2) <= h and sum * sum <= (sum - w) * (sum - w) + (sum - h) * (sum - h) ? "S\n" : "N\n");
	}
	return 0;
}

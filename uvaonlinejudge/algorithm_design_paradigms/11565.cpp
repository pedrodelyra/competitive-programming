#include <bits/stdc++.h>

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		for(int x = -100; x <= 100; ++x) {
			for(int y = -100; y <= 100; ++y) {
				for(int z = -100; z <= 100; ++z) {
					if(x == y || x == z || y == z) continue;

					if((x + y + z) == a && (x * y * z) == b && (x * x + y * y + z * z) == c) {
						printf("%d %d %d\n", x, y, z);
						goto end_tc;
					}
				}
			}
		}

		printf("No solution.\n");
end_tc:;
	}

	return 0;
}

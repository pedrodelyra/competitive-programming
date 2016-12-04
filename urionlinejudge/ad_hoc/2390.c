#include <stdio.h>

#define min(x, y) ((x) < (y) ? (x) : (y))

int main(void) {
	int n, i, j, total_time = 0;
	scanf("%d %d", &n, &i);
	j = i + 10;
	while(--n) {
		int t;
		scanf("%d", &t);
		if(t <= j) {
			j = t + 10;
		} else {
			total_time += j - i;
			i = t;
			j = i + 10;
		}
	}
	total_time += j - i;
	printf("%d\n", total_time);
	return 0;
}

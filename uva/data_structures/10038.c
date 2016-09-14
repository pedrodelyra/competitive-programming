#include <stdio.h>
#include <string.h>

#define MAX 4096
#define bool unsigned
#define true 1
#define false 0

int array[MAX];

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		int i;
		for(i = 0; i < n; ++i) {
			scanf("%d", &array[i]);
		}

		bool is_possible[n];
		memset(is_possible, false, sizeof is_possible);
		for(i = 0; i < n - 1; ++i) {
			int abs_value = abs(array[i] - array[i + 1]);
			if(abs_value >= 1 && abs_value < n) {
				is_possible[abs_value] = true;
			}
		}

		bool flag = true;
		for(i = 1; i < n; ++i) {
			if(!is_possible[i]) {
				flag = false;
				break;
			}
		}

		printf(flag ? "Jolly\n" : "Not jolly\n");
	}

	return 0;
}

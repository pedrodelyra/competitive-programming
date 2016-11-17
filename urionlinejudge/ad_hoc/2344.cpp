#include <cstdio>

int main(void) {
	int n;
	scanf("%d", &n);
	if(1 <= n and n <= 35) {
		printf("D\n");
	} else if(36 <= n and n <= 60) {
		printf("C\n");
	} else if(61 <= n and n <= 85) {
		printf("B\n");
	} else if(86 <= n and n <= 100) {
		printf("A\n");
	} else {
		printf("E\n");
	}
	return 0;
}

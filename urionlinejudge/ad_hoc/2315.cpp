#include <cstdio>

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void) {
	int d1, m1, d2, m2;
	scanf("%d %d %d %d", &d1, &m1, &d2, &m2);
	int d = 0;
	for(int i = m1; i < m2; ++i) {
		d += days[i - 1];
	}
	printf("%d\n", d - d1 + d2);
	return 0;
}

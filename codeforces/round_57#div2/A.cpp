#include <bits/stdc++.h>

using namespace std;

int main(void) {
	char A[105], B[105];
	scanf("%s %s", A, B);
	for(int i = 0; A[i] and B[i]; ++i) {
		printf("%d", (A[i] - '0') ^ (B[i] - '0'));
	}
	return 0;
}

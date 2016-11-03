#include <bits/stdc++.h>

using namespace std;

int main(void) {
	char A[128], B[128];
	scanf("%s %s", A, B);
	for(int i = 0; A[i] and B[i]; ++i) {
		A[i] = toupper(A[i]);
		B[i] = toupper(B[i]);
	}
	int diff = strcmp(A, B);
	printf("%d\n", diff / max(abs(diff), 1));
	return 0;
}

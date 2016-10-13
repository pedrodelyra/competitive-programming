#include <bits/stdc++.h>

using namespace std;

char A[128], B[128];

bool is_palindrome(int i, int j) {
	if(i >= j) return true;

	return B[i] == B[j] && is_palindrome(i + 1, j - 1);
}

int main(void) {
	string vowels = "aeiou";
	scanf("%s", A);
	int k = 0;
	for(int i = 0; A[i]; ++i)
		if(~vowels.find(A[i])) B[k++] = A[i];
	printf(is_palindrome(0, k - 1) ? "S\n" : "N\n");
	return 0;
}

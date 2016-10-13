#include <bits/stdc++.h>

#define MAX 1024

using namespace std;

string str;
int dp[MAX][MAX];

int longest_palindrome(int i, int j) {
	if(i == j) {
		return 1;
	} else if(i + 1 == j) {
		return (str[i] == str[j]) + 1;
	} else if(~dp[i][j]) {
		return dp[i][j];
	}

	if(str[i] == str[j]) {
		return dp[i][j] = longest_palindrome(i + 1, j - 1) + 2;
	} else {
		return dp[i][j] = max(longest_palindrome(i + 1, j), longest_palindrome(i, j - 1));
	}
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	getchar();
	while(tc--) {
		getline(cin, str);
		memset(dp, -1, sizeof dp);
		dp[0][0] = 0;
		printf("%d\n", longest_palindrome(0, str.length() - 1));
	}

	return 0;
}

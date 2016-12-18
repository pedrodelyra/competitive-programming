#include <bits/stdc++.h>

#define MAX 1024

using namespace std;

char str[MAX], chars[5] = {'A', 'C', 'G', 'T'};

int main(void) {
	int n;
	scanf("%d %s", &n, str);
	if(n % 4) {
		printf("===\n");
	} else {
		int m = n / 4, f[MAX] = {0};
		for(int i = 0; str[i]; ++i) f[str[i]]++;
		for(int i = 0, j; str[i]; ++i) {
			if(str[i] == '?') {
				for(j = 0; f[chars[j]] == m and j < 4; ++j);
				f[str[i] = chars[j]]++;
			}
		}
		bool possible = true;
		for(int j = 0; chars[j + 1]; ++j) {
			if(f[chars[j]] != f[chars[j + 1]]) possible = false;
		}
		printf("%s\n", possible ? str : "===");
	}
	return 0;
}

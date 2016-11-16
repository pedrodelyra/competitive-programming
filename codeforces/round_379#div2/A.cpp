#include <bits/stdc++.h>

using namespace std;

int f[255];

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		char c;
		scanf(" %c", &c);
		f[c]++;
	}

	if(f['A'] > f['D']) {
		printf("Anton\n");
	} else if(f['D'] > f['A']) {
		printf("Danik\n");
	} else {
		printf("Friendship\n");
	}
	return 0;
}

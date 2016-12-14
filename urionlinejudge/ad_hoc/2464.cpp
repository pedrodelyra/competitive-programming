#include <bits/stdc++.h>

using namespace std;

int main(void) {
	char alphabet[32], message[10005], code[256];
	scanf(" %s %s", alphabet, message);
	for(int i = 0; alphabet[i]; ++i) {
		code[alphabet[i]] = i + 'a';
	}
	for(int i = 0; message[i]; ++i) {
		printf("%c", code[message[i]]);
	}
	printf("\n");
	return 0;
}

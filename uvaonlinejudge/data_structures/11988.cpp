#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

char str[MAX];

int main(void) {
	while(scanf(" %[^\n]\n", str) != EOF) {
		list<char> l;
		list<char>::iterator it = l.begin();
		for(int i = 0; str[i]; ++i) {
			if(str[i] == '[') {
				it = l.begin();
			} else if(str[i] == ']') {
				it = l.end();
			} else {
				l.insert(it, str[i]);
			}
		}

		for(auto& c : l) {
			printf("%c", c);
		}

		printf("\n");
	}

	return 0;
}

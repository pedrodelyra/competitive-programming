#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

map<char, char> enclosing = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		char str[MAX];
		scanf(" %s", str);
		stack<char> s; bool valid_expression = true;
		for(int i = 0; valid_expression and str[i]; ++i) {
			if(str[i] == '(' or str[i] == '[' or str[i] == '{') {
				s.push(str[i]);
			} else {
				if(not s.empty() and enclosing[s.top()] == str[i]) {
					s.pop();
				} else {
					valid_expression = false;
				}
			}
		}
		printf(s.empty() and valid_expression ? "S\n" : "N\n");
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, current_word = 0, max_word = 0, count = 0, inside_parenthesis = false;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		char c;
		scanf(" %c", &c);
		if(c == '(') {
			if(current_word) {
				max_word = max(max_word, current_word);
				current_word = 0;
			}
			inside_parenthesis = true;
		} else if(c == ')') {
			if(current_word) {
				count++;
				current_word = 0;
			}
			inside_parenthesis = false;
		} else {
			if(c == '_') {
				if(inside_parenthesis) {
					if(current_word) {
						count++;
						current_word = 0;
					}
				} else {
					max_word = max(max_word, current_word);
					current_word = 0;
				}
			} else {
				++current_word;
			}
		}
	}
	printf("%d %d\n", max(max_word, current_word), count);
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, tc = 0;
	while(scanf("%d\n", &n), n) {
		vector<string> lines(n + 1, "");
		int max_length = 0;
		for(int i = 1; i <= n; ++i) {
			string in, word;
			getline(cin, in);
			stringstream ss(in);
			while(ss >> word) {
				lines[i] += (lines[i].empty() ? "" : " ") + word;
			}
			max_length = max(max_length, (int) lines[i].length());
		}
		if(tc++) printf("\n");
		for(int i = 1; i <= n; ++i) {
			printf("%*s\n", max_length, lines[i].c_str());
		}
	}
	return 0;
}

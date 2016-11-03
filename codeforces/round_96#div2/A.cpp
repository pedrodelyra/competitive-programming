#include <bits/stdc++.h>

using namespace std;

int main(void) {
	string p;
	getline(cin, p);
	bool ans = false;
	for(int i = 0; p[i]; ++i) {
		ans = ans || (p[i] == 'H' || p[i] == 'Q' || p[i] == '9');
	}
	printf(ans ? "YES\n" : "NO\n");
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void) {
	string name;
	cin >> name;
	set<char> s;
	for(auto& c : name) s.insert(c);
	printf(s.size() & 1 ? "IGNORE HIM!\n" : "CHAT WITH HER!\n");
	return 0;
}

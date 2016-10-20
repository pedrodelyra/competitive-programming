#include <bits/stdc++.h>

using namespace std;

class friend_t {
public:
	string name;
	int id;

	friend_t(string str, int n) : name(str), id(n) {}

	bool operator<(const friend_t& other) const {
		if(name.length() == other.name.length()) {
			return id > other.id;
		} else {
			return name.length() < other.name.length();
		}
	}
};

int main(void) {
	set<string> friends, enemies;
	priority_queue<friend_t> pq;
	char name[128], answer[10];
	int  k = 0;
	while(scanf(" %s %s", name, answer), strcmp(name, "FIM")) {
		if(!strcmp(answer, "NO")) {
			enemies.insert(name);
		} else {
			friends.insert(name);
			pq.push(friend_t(name, ++k));
		}
	}

	for(auto& s : friends) {
		printf("%s\n", s.c_str());
	}

	for(auto& s : enemies) {
		printf("%s\n", s.c_str());
	}

	printf("\nAmigo do Habay:\n");
	if(not pq.empty()) printf("%s\n", pq.top().name.c_str());

	return 0;
}

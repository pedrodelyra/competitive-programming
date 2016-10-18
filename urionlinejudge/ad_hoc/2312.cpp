#include <bits/stdc++.h>

using namespace std;

class country {
public:
	int gold, silver, bronze;
	string name;

	country(string s, int x, int y, int z) : name(s), gold(x), silver(y), bronze(z) {}

	bool operator<(const country& c) const {
		if(gold == c.gold) {
			if(silver == c.silver) {
				if(bronze == c.bronze) {
					return name < c.name;
				} else {
					return bronze > c.bronze;
				}
			} else {
				return silver > c.silver;
			}
		} else {
			return gold > c.gold;
		}
	}
};

int main(void) {
	int n;
	scanf("%d", &n);
	vector<country> teams;
	for(int i = 0; i < n; ++i) {
		char name[128];
		int  gold, silver, bronze;
		scanf(" %s %d %d %d", name, &gold, &silver, &bronze);
		teams.push_back(country(name, gold, silver, bronze));	
	}
	sort(teams.begin(), teams.end());
	for(auto& t : teams) {
		printf("%s %d %d %d\n", t.name.c_str(), t.gold, t.silver, t.bronze);
	}
	return 0;
}

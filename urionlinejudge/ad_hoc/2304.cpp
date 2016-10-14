#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n, m, money[255];
	scanf("%d %d", &n, &m);
	money['D'] = money['E'] = money['F'] = n;
	while(m--) {
		char cmd;
		scanf(" %c", &cmd);

		if(cmd == 'C') {
			char player; int x;
			scanf(" %c %d", &player, &x);
			money[player] -= x;
		}

		if(cmd == 'V') {
			char player; int x;
			scanf(" %c %d", &player, &x);
			money[player] += x;
		}

		if(cmd == 'A') {
			char _1st_player, _2nd_player; int x;
			scanf(" %c %c %d", &_1st_player, &_2nd_player, &x);
			money[_1st_player] += x;
			money[_2nd_player] -= x;
		}
	}
	printf("%d %d %d\n", money['D'], money['E'], money['F']);
	return 0;
}

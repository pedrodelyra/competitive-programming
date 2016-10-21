#include <bits/stdc++.h>

#define MAX_HP  2048
#define MAX_ATK 205
#define MAX_DEF 105
#define oo	0x2f2f2f2f

using namespace std;

int cost_hp, cost_atk, cost_def, monster_hp, monster_atk, monster_def;

bool wins(int hp, int atk, int def) {
	int hp_lost = monster_atk - def, monster_hp_lost = atk - monster_def;
	if(monster_hp_lost <= 0) {
		return false;
	} else {
		int n = monster_hp / monster_hp_lost + (monster_hp % monster_hp_lost != 0);
		if(hp_lost <= 0) {
			return n > 0;
		} else {
			int m = hp / hp_lost + (hp % hp_lost != 0);
			return n < m;
		}
	}
}

int main(void) {
	int hp, atk, def;
	scanf("%d %d %d", &hp, &atk, &def);
	scanf("%d %d %d", &monster_hp, &monster_atk, &monster_def);
	scanf("%d %d %d", &cost_hp, &cost_atk, &cost_def);
	int ans = oo;
	for(int j = atk; j <= MAX_ATK; ++j) {
		for(int k = def; k <= MAX_DEF; ++k) {
			for(int i = hp; i <= MAX_HP; ++i) {
				if(wins(i, j, k)) {
					ans = min(ans, (i - hp) * cost_hp + (j - atk) * cost_atk + (k - def) * cost_def);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

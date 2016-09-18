#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int main(void) {
	int n, tc = 0;
	while(scanf("%d", &n), n) {
		vector<ii> students(n);
		int max_score = 0;
		for(int i = 0; i < n; ++i) {
			int id, score;
			scanf("%d %d", &id, &score);
			students[i] = ii(id, score);
			max_score = max(max_score, score);
		}

		vector<int> ans;
		for(int i = 0; i < n; ++i) {
			int id = students[i].first, score = students[i].second;
			if(score == max_score) ans.push_back(id);
		}

		printf("Turma %d\n", ++tc);
		for(auto& id : ans) {
			printf("%d ", id);
		}
		printf("\n\n");
	}

	return 0;
}

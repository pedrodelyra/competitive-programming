#include <bits/stdc++.h>

#define INF 1 << 30

using namespace std;

class student {
public:
	int score;
	string name;

	student(string n = "", int s = 0) : name(n), score(s) {}

	bool operator<(const student& s) const {
		if(this->score == s.score) {
			return this->name < s.name;
		} else {
			return this->score > s.score;
		}
	}
};

int main(void) {
	int n, tc = 0;
	while(scanf("%d", &n), n) {
		vector<student> students(n);
		for(int i = 0; i < n; ++i) {
			char name[128];
			scanf(" %s", name);
			int max_score = 0, min_score = INF, sum = 0;
			for(int j = 0; j < 12; ++j) {
				int score;
				scanf("%d" , &score);
				max_score = max(max_score, score);
				min_score = min(min_score, score);
				sum += score;
			}

			students[i] = student(name, sum - max_score - min_score);
		}

		sort(students.begin(), students.end());

		int ranking = 1;
		printf("Teste %d\n", ++tc);
		for(int i = 0; i < n; ++i) {
			if(i && students[i].score < students[i - 1].score) ranking = i + 1;
			printf("%d %d %s\n", ranking, students[i].score, students[i].name.c_str());
		}
		printf("\n");
	}

	return 0;
}

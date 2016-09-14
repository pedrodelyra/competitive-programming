#include <bits/stdc++.h>

#define INF (1 << 30)
#define HORIZONTAL 1
#define VERTICAL 2

using namespace std;
using ii = pair<int, int>;
using parent = pair<string, ii>;

char puzzle[15], source_puzzle[15] = "123456789";
map<string, int> dist;
map<string, parent> parents;

void bfs(void) {
	queue<string> q;
	dist[source_puzzle] = 1;
	q.push(source_puzzle);
	while(not q.empty()) {
		auto current_puzzle = q.front();

		for(int i = 0; i < 3; ++i) {
			string next_puzzle = current_puzzle;
			char buffer = next_puzzle[3 * i];

			for(int j = 0; j < 2; ++j) {
				next_puzzle[3 * i + j] = next_puzzle[3 * i + j + 1];
			}
			next_puzzle[3 * i + 2] = buffer;

			if(dist[next_puzzle] == 0) {
				parents[next_puzzle] = parent(current_puzzle, ii(HORIZONTAL, i));
				dist[next_puzzle] = dist[current_puzzle] + 1;
				q.push(next_puzzle);
			}

			next_puzzle = current_puzzle;
			buffer = next_puzzle[6 + i];

			for(int j = 2; j > 0; --j) {
				next_puzzle[3 * j + i] = next_puzzle[3 * (j - 1) + i];
			}
			next_puzzle[i] = buffer;

			if(dist[next_puzzle] == 0) {
				parents[next_puzzle] = parent(current_puzzle, ii(VERTICAL, i));
				dist[next_puzzle] = dist[current_puzzle] + 1;
				q.push(next_puzzle);
			}

		}

		q.pop();
	}
}

int main(void) {
	int n;
	bfs();
	while(scanf("%d", &n), n) {
		puzzle[0] = n + '0';
		for(int i = 1; i <= 8; ++i) {
			scanf("%d", &n);
			puzzle[i] = n + '0';
		}

		if(dist[puzzle] == 0) {
			printf("Not solvable\n");
		} else {
			printf("%d ", dist[puzzle] - 1);
			string s = puzzle;
			while(not parents[s].first.empty()) {
				auto current_move = parents[s].second;
				printf("%c%d", current_move.first == HORIZONTAL ? 'H' : 'V', current_move.second + 1);
				s = parents[s].first;
			}
			printf("\n");
		}
	}

	return 0;
}

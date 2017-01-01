#include <bits/stdc++.h>

#define oo 0x3f3f3f3f

using namespace std;
using vi  = vector<int>;
using msi = unordered_map<string, int>;
using mss = unordered_map<string, string>;

msi dist;
mss parents;
vi transitions[9] = {{3, 1}, {4, 2, 0}, {5, 1}, {0, 6, 4}, {1, 7, 5, 3}, {2, 8, 4}, {3, 7}, {4, 8, 6}, {5, 7}};
const string destination = "123456780";

int bfs(string source) {
	queue<string> q;
	dist[source] = 1;
	q.push(source);
	while(not q.empty()) {
		auto current_state = q.front(); q.pop();

		if(current_state == destination) return dist[current_state] - 1;

		int current_pos = current_state.find('0');
		for(auto& next_pos : transitions[current_pos]) {
			auto next_state = current_state;
			swap(next_state[current_pos], next_state[next_pos]);
			if(dist[next_state] == 0) {
				dist[next_state] = dist[current_state] + 1;
				parents[next_state] = current_state;
				q.push(next_state);
			}
		}
	}
	return oo;
}

void rebuild_path(string u) {
	if(not parents[u].empty()) {
		rebuild_path(parents[u]);
		printf("\n");
		for(int i = 0; i < 9; ++i) printf("%c%s", u[i], (i + 1) % 3 == 0 ? "\n" : "");
	}
}

int main(void) {
	char source[10] {0};
	while(~scanf(" %c", &source[0])) {
		for(int i = 1; i < 9; ++i) {
			scanf(" %c", &source[i]);
		}
		int min_moves = bfs(source);
		if(min_moves < oo) {
			printf("Quantidade minima de passos = %d", min_moves);
			rebuild_path(destination);
		} else {
			printf("Problema sem solucao\n");
		}
		dist.clear();
		parents.clear();
	}
	return 0;
}

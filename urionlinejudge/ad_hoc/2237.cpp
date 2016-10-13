#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using state = pair<int, vi>;

map<vi, int> dist;

int dijkstra(vi& source, vi& destination) {
	priority_queue<state, vector<state>, greater<state>> pq;
	dist[source] = 1;
	pq.push(state(dist[source], source));
	while(not pq.empty()) {
		auto current_state = pq.top(); pq.pop();
		auto current_dist = current_state.first;
		auto current_grid = current_state.second;

		if(current_dist > dist[current_grid]) continue;

		if(current_grid == destination) break;

		for(int i = 0; i < 7; ++i) {
			int w;
			if(i != 3) {
				w = current_grid[i] + current_grid[i + 1];
				swap(current_grid[i], current_grid[i + 1]);
				if(dist[current_grid] == 0 || dist[current_grid] > current_dist + w) {
					dist[current_grid] = current_dist + w;
					pq.push(state(dist[current_grid], current_grid));
				}
				swap(current_grid[i], current_grid[i + 1]);
			}

			if(i <= 3) {
				w = current_grid[i] + current_grid[i + 4];
				swap(current_grid[i], current_grid[i + 4]);
				if(dist[current_grid] == 0 || dist[current_grid] > current_dist + w) {
					dist[current_grid] = current_dist + w;
					pq.push(state(dist[current_grid], current_grid));
				}
				swap(current_grid[i], current_grid[i + 4]);
			}
		}
	}

	return dist[destination] - 1;
}

int main(void) {
	vector<int> source(8), destination(8);
	for(int i = 0; i < 8; ++i) {
		scanf("%d", &source[i]);
	}

	for(int i = 0; i < 8; ++i) {
		scanf("%d", &destination[i]);
	}

	printf("%d\n", dijkstra(source, destination));

	return 0;
}

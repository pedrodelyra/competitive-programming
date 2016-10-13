#include <bits/stdc++.h>

#define MAX 4096
#define INF -1

using namespace std;
using ii = pair<int, int>;
using iic = pair<ii, char>;

map<string, int> str_to_id;
vector<string> common_words[MAX][MAX];

vector<int> graph[MAX];
unsigned dist[MAX][255];

unsigned dijkstra(int source, int destination) {
	priority_queue<iic, vector<iic>, greater<iic>> pq;
	memset(dist, INF, sizeof dist);
	dist[source][0] = 0;
	pq.push(iic(ii(dist[source][0], source), 0));

	while(not pq.empty()) {
		auto current = pq.top();
		pq.pop();

		int u = current.first.second, current_dist = current.first.first;
		char last_char = current.second;

		if(current_dist > dist[u][last_char]) continue;

		for(auto& v : graph[u]) {
			for(auto word : common_words[u][v]) {
				if(word[0] != last_char) {
					int w = word.length();
					if(dist[v][word[0]] > dist[u][last_char] + w) {
						dist[v][word[0]] = dist[u][last_char] + w;
						pq.push(iic(ii(dist[v][word[0]], v), word[0]));
					}
				}
			}
		}
	}

	unsigned min_dist = INF;
	for(int i = 0; i < 255; ++i)
		min_dist = min(min_dist, dist[destination][i]);

	return min_dist;
}

int main(void) {
	int n;
	while(scanf("%d", &n), n) {
		int k = 1;
		char source[255], destination[255];
		scanf(" %s %s", source, destination);
		if(not str_to_id[source])
			str_to_id[source] = k++;

		if(not str_to_id[destination])
			str_to_id[destination] = k++;

		for(int i = 0; i < n; ++i) {
			char l1[255], l2[255], word[255];
			scanf(" %s %s %s", l1, l2, word);

			if(not str_to_id[l1]) {
				str_to_id[l1] = k++;
			}

			if(not str_to_id[l2]) {
				str_to_id[l2] = k++;
			}

			int u = str_to_id[l1], v = str_to_id[l2];
			graph[u].push_back(v);
			graph[v].push_back(u);

			common_words[u][v].push_back(word);
			common_words[v][u].push_back(word);
		}

		unsigned min_dist = dijkstra(str_to_id[source], str_to_id[destination]);
		printf(min_dist < INF ? "%d\n" : "impossivel\n", min_dist);

		for(int u = 1; u < k; ++u) {
			graph[u].clear();
			for(int v = 1; v < k; ++v) {
				common_words[u][v].clear();
			}
		}

		str_to_id.clear();
	}

	return 0;
}

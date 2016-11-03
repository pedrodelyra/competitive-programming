#include <bits/stdc++.h>

#define oo 0x2f2f2f2f

using namespace std;

map<string, vector<string>> graph;
map<string, int> dist;

int bfs(string source, string destination) {
	queue<string> q;
	dist[source] = 1;
	q.push(source);
	while(not q.empty()) {
		auto u = q.front();

		if(u == destination) return dist[destination] - 1;

		for(auto& v : graph[u]) {
			if(dist[v] == 0) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		q.pop();
	}
	return oo;
}

int main(void) {
	int n;
	cin >> n;
	set<string> s;
	for(int i = 0; i < n; ++i) {
		string A, B;
		cin >> A >> B;
		replace(A.begin(), A.end(), '_', '@');
		replace(B.begin(), B.end(), '_', '@');
		graph[A].push_back(B);
		s.insert(A), s.insert(B);
	}
	vector<string> articles(s.begin(), s.end());
	int m = articles.size();
	for(int i = 0; i < m; ++i) {
		if(i + 1 <  m) graph[articles[i]].push_back(articles[i + 1]);
		if(i - 1 >= 0) graph[articles[i]].push_back(articles[i - 1]);
	}
	string source, destination;
	cin >> source >> destination;
	replace(source.begin(), source.end(), '_', '@');
	replace(destination.begin(), destination.end(), '_', '@');
	printf("%d\n", bfs(source, destination));
	return 0;
}

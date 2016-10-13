#include <bits/stdc++.h>

using namespace std;

class union_find {
private:
	vector<int> parents, rank;

public:
	union_find(int n) : parents(n + 1), rank(n + 1, 0) {
		for(int i = 1; i <= n; ++i) {
			parents[i] = i;
		}
	}

	int find_set(int u) {
		return u == parents[u] ? u : (parents[u] = find_set(parents[u]));
	}

	bool same_set(int u, int v) {
		return find_set(u) == find_set(v);
	}

	void union_set(int u, int v) {
		if(not same_set(u, v)) {
			int x = parents[u], y = parents[v];

			if(rank[x] > rank[y]) {
				parents[y] = parents[x];
			} else {
				parents[x] = parents[y];
			}

			if(rank[x] == rank[y]) ++rank[x];
		}
	}
};

int main(void) {
	int tc;
	scanf("%d", &tc);

	for(int t = 0; t < tc; ++t) {
		int n, right = 0, wrong = 0;
		scanf("%d\n", &n);

		union_find ufds(n);
		char command_line[255], command;
		while(gets(command_line) && *command_line) {
			int u, v;
			sscanf(command_line, "%c %d %d", &command, &u, &v);
			if(command == 'c') {
				ufds.union_set(u, v);
			}

			if(command == 'q') {
				bool connected = ufds.same_set(u, v);
				right += connected;
				wrong += not connected;
			}
		}

		if(t) { printf("\n"); }

		printf("%d,%d\n", right, wrong);
	}

	return 0;
}

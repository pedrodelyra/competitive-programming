#include <bits/stdc++.h>

using namespace std;

map<string, int> trees_frequences;

int main(void) {
	int n;
	scanf("%d\n\n", &n);
	for(int tc = 0; tc < n; ++tc) {
		char str[64];
		int total_trees = 0;
		while(gets(str) && *str) {
			trees_frequences[str]++;	
			total_trees++;
		}

		if(tc) { printf("\n"); }
		for(auto& tree_freq : trees_frequences) {
			printf("%s %.4lf\n", tree_freq.first.c_str(), 100.0 * tree_freq.second / (double) total_trees); 
		}

		trees_frequences.clear();
	}

	return 0;
}

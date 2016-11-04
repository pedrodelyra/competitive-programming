#include <bits/stdc++.h>

using namespace std;

int frequences[1024];

int main(void) {
	int p, n;
	scanf("%d %d", &p, &n);
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		frequences[x]++;
	}
	int  max_frequence = frequences[p], min_frequence = frequences[p];
	bool decreasing = true;
	for(int i = 1; decreasing and i < p; ++i) {
		max_frequence = max(max_frequence, frequences[i]);
		min_frequence = min(min_frequence, frequences[i]);
		decreasing = decreasing and (frequences[i] >= frequences[i + 1]);
	}
	int max_diff = abs(max_frequence - min_frequence);
	printf(max_diff <= 1 and decreasing ? "S\n" : "N\n");
	return 0;
}

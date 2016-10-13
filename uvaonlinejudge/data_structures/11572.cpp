#include <bits/stdc++.h>

using namespace std;

map<int, int> last_index;

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n, current_sequence_size, max_sequence_size, last_not_unique;
		scanf("%d", &n);
		current_sequence_size = max_sequence_size = last_not_unique =  0;
		for(int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);

			if(last_index[x] > 0) {
				last_not_unique = max(last_not_unique, last_index[x]);
				current_sequence_size = i - last_not_unique - 1;
			}

			last_index[x] = i;
			current_sequence_size++;
			max_sequence_size = max(max_sequence_size, current_sequence_size);
		}

		printf("%d\n", max_sequence_size);
		last_index.clear();
	}

	return 0;
}

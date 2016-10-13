#include <bits/stdc++.h>

#define MAX 100005
#define INF (1 << 30)

int bsearch(int* array, int begin, int end, int value) {
	while(begin <= end) {
		int mid = (begin + end) / 2;
		if(array[mid] == value) {
			return array[mid];
		} else if(array[mid] < value) {
			begin = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	return -1;
}

int main(void) {
	int n;
	while(scanf("%d", &n) != EOF) {
		int books[MAX];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &books[i]);
		}

		std::sort(books, books + n);

		int money, x = 0, y = INF;
		scanf("%d", &money);

		for(int i = 0; i < n - 1; ++i) {
			int price = bsearch(books, i + 1, n - 1, money - books[i]);
			if(price >= 0) {
				if(price - books[i] < y - x) {
					x = books[i];
					y = price;
				}
			}
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", x, y);
	}

	return 0;
}

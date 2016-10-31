#include <bits/stdc++.h>

using namespace std;

map<int, int> cards {{4,  1}, {5,  2}, {6, 3}, {7, 4}, {12, 5},
		     {11, 6}, {13, 7}, {1, 8}, {2, 9}, {3, 10}};

int main(void) {
	int a = 0, b = 0, tc;
	scanf("%d", &tc);
	while(tc--) {
		int A[3], B[3];
		for(int i = 0; i < 3; ++i) {
			scanf("%d", &A[i]);
		}

		for(int i = 0; i < 3; ++i) {
			scanf("%d", &B[i]);
		}

		int x = 0, y = 0;
		for(int i = 0; i < 3; ++i) {
			if(cards[A[i]] >= cards[B[i]]) ++x;
			if(cards[B[i]] >  cards[A[i]]) ++y;
		}
		a += x > y;
		b += x < y;
	}
	printf("%d %d\n", a, b);
	return 0;
}

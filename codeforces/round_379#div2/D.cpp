#include <bits/stdc++.h>

#define MAX 500005
#define oo  (1LL << 63)

using namespace std;
using lld = long long int;
using llu = unsigned long long int;
using iii = tuple<char, lld, lld>;

iii A[MAX];

bool is_north(lld kx, lld ky, lld x, lld y) { return ky == y and x > kx; }

bool is_south(lld kx, lld ky, lld x, lld y) { return ky == y and x < kx; }

bool is_east(lld kx, lld ky, lld x, lld y) { return kx == x and y > ky; }

bool is_west(lld kx, lld ky, lld x, lld y) { return kx == x and y < ky; }

bool is_north_east(lld kx, lld ky, lld x, lld y) { return x > kx and y > ky and abs(x - kx) == abs(y - ky); }

bool is_south_east(lld kx, lld ky, lld x, lld y) { return x > kx and y < ky and abs(x - kx) == abs(y - ky); }

bool is_north_west(lld kx, lld ky, lld x, lld y) { return x < kx and y > ky and abs(x - kx) == abs(y - ky); }

bool is_south_west(lld kx, lld ky, lld x, lld y) { return x < kx and y < ky and abs(x - kx) == abs(y - ky); }

bool in_check(int dir, char c) { return c == 'Q' or (dir < 4 and c == 'R') or (dir >= 4 and c == 'B'); }

bool (*is_in[8])(lld, lld, lld, lld) = {is_north, is_south, is_east, is_west, is_north_east, is_south_east, is_north_west, is_south_west};

llu dist_squared(lld kx, lld ky, lld x, lld y) {
        return 1LL * (kx - x) * (kx - x) + (ky - y) * (ky - y);
}

int main(void) {
        int n, p;
        scanf("%d", &n);
        lld kx, ky; llu min_dist;
        scanf("%lld %lld", &kx, &ky);
        for(int i = 1; i <= n; ++i) {
                char c; lld x, y;
                scanf(" %c %lld %lld", &c, &x, &y);
                A[i] = iii(c, x, y);
        }

        bool ans = false;
	for(int curr_dir = 0; !ans and curr_dir < 8; ++curr_dir) {
		min_dist = oo, p = -1;
		for(int i = 1; !ans and i <= n; ++i) {
			char c; lld x, y;
			tie(c, x, y) = A[i];
			if(is_in[curr_dir](kx, ky, x, y)) {
				llu d = dist_squared(kx, ky, x, y);
				if(d < min_dist) {
					min_dist = d;
					p = i;
				}
			}
		}
		if(~p) {
			char c; lld x, y;
			tie(c, x, y) = A[p];
			if(in_check(curr_dir, c)) {
				ans = true;
			}
		}
	}
        printf(ans ? "YES\n" : "NO\n");
	return 0;
}

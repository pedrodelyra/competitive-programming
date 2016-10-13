#include <bits/stdc++.h>

using namespace std;

int k, nums[22], dp[1 << 22];

int main(void) {
        int tc;
        scanf("%d\n", &tc);
        while(tc--) {
                string str;
                getline(cin, str);

                stringstream ss(str);
                int x;
                k = 0;
                while(ss >> x) {
                        nums[k++] = x;
                }

                bool result = false;
                for(int mask = 1; mask < (1 << k) - 1; ++mask) {
                        int _1st_boat = 0, _2nd_boat = 0;
                        for(int i = 0; i < k; ++i) {
                                _1st_boat += ((mask >> i) & 1) * nums[i];
                                _2nd_boat += !((mask >> i) & 1) * nums[i];
                        }

                        if(_1st_boat == _2nd_boat) {
                                result = true;
                                break;
                        }
                }

                printf(result ? "YES\n" : "NO\n");
        }

        return 0;
}

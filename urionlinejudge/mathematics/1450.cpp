#include <bits/stdc++.h>

using namespace std;

const int oo = 0x3f3f3f3f;

class block {
public:
        int height, width, length;
        block(int h = 0, int w = oo, int l = oo) : height(h), width(w), length(l) {}
};

vector<block> blocks[20];
int n, dp[16][8][1 << 16];

int solve(int u, int r, int mask) {
        if(mask + 1 == 1 << n) {
                return 0;
        } else if(~dp[u][r][mask]) {
                return dp[u][r][mask];
        } else {
                int max_height = 0;
                for(int i = 1; i <= n; ++i) {
                        if((mask >> i & 1) == 0) {
                                for(int j = 0; j < blocks[i].size(); ++j) {
                                        if(blocks[u][r].length >= blocks[i][j].length &&
                                           blocks[u][r].width >= blocks[i][j].width) {
                                                max_height = max(max_height, solve(i, j, mask | (1 << i)));
                                        }
                                }
                        }
                }
                return dp[u][r][mask] = max_height + blocks[u][r].height;
        }
}

int main() {
        int tc;
        cin >> tc;
        blocks[0].push_back(block());
        while(tc--) {
                cin >> n;
                for(int i = 1; i <= n; ++i) {
                        int x, y, z;
                        cin >> x >> y >> z;
                        vector<int> dimensions {x, y, z};
                        sort(dimensions.begin(), dimensions.end());
                        do {
                                blocks[i].push_back(block(dimensions[0],
                                                          dimensions[1],
                                                          dimensions[2]));
                        } while(next_permutation(dimensions.begin(), dimensions.end()));
                }
                memset(dp, -1, sizeof dp);
                cout << solve(0, 0, 0) << endl;
                for(int i = 1; i <= n; ++i) {
                        blocks[i].clear();
                }
        }
        return 0;
}

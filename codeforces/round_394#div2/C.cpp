#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 64, oo = 1e9;

vector<string> words(MAX_N);
int n, m, dp[MAX_N][2][2][2];

bool issymbol(char c) { return c == '#' or c == '*' or c == '&'; }

int solve(int i, bool found_digit, bool found_lowercase, bool found_symbol) {
        if(found_digit and found_lowercase and found_symbol) {
                return 0;
        } else if(i == n) {
                return oo;
        } else if(~dp[i][found_digit][found_lowercase][found_symbol]) {
                return dp[i][found_digit][found_lowercase][found_symbol];
        } else {
                int ans = solve(i + 1, found_digit     | isdigit(words[i][0]),
                                       found_lowercase | isalpha(words[i][0]),
                                       found_symbol    | issymbol(words[i][0]));
                for(int j = 1; j < m; ++j) {
                        ans = min(ans, solve(i + 1, found_digit     | isdigit(words[i][j]),
                                                    found_lowercase | isalpha(words[i][j]),
                                                    found_symbol    | issymbol(words[i][j])) + min(j, m - j));
                }
                return dp[i][found_digit][found_lowercase][found_symbol] = ans;
        }
}


int main() {
        cin >> n >> m;
        for(int i = 0; i < n; ++i) cin >> words[i];
        memset(dp, -1, sizeof dp);
        cout << solve(0, false, false, false) << endl;
        return 0;
}

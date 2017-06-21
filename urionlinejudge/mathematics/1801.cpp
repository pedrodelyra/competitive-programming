#include <bits/stdc++.h>

using namespace std;
using lld = long long int;

const lld MAX = 1e13 + 5;
int hist[10] = {0}, macumba[10] = {0};
lld x;

inline bool good(lld y) {
        memset(macumba, 0, sizeof macumba);
        while(y) {
                macumba[y % 10]++;
                y /= 10;
        }
        for(int i = 0; i < 10; i++) {
                if(hist[i] != macumba[i]) {
                        return false;
                }
        }
        return true;
}

int main() {
        lld x;
        cin >> x;
        string hu3 = to_string(x);
        sort(hu3.begin(), hu3.end(), greater<char>());
        lld y = x + stoll(hu3);
        vector<lld> s;
        for(lld i = sqrt(x); i * i <= y; ++i)
                if(i * i >= x)
                        s.push_back(i * i);
        auto _x = x;
        while(_x) {
                hist[_x % 10]++;
                _x /= 10;
        }
        int count = 0;
        for(const auto& p : s) {
                if(good(p - x)) {
                        ++count;
                }
        }
        cout << count << endl;
        return 0;
}

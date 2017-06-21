#include <bits/stdc++.h>

using namespace std;

map<string, int> m;
set<string> s;

int main() {
        string a, b;
        while(cin >> a >> b) {
                m[a]++;
                s.insert(b);
        }
        cout << "HALL OF MURDERERS" << endl;
        for(auto& p : m) {
                if(s.count(p.first) == 0) {
                        cout << p.first << " " << p.second << endl;
                }
        }
        return 0;
}

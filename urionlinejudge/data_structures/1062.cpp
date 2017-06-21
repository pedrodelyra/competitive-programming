#include <bits/stdc++.h>

using namespace std;

int main() {
        int n;
        while(cin >> n, n) {
                vector<int> a(n);
                while(scanf("%d", &a[0]), a[0]) {
                        int top = 0;
                        for(int i = 1; i < n; ++i) {
                                scanf("%d", &a[i]);
                        }
                        stack<int> s;
                        for(int i = 0; i < n; ++i) {
                                if(s.empty() or s.top() != a[i]) {
                                        while(top <= n and top != a[i]) s.push(++top);
                                }
                                if(s.top() == a[i]) s.pop();
                        }
                        cout << (s.empty() ? "Yes" : "No") << endl;
                }
                cout << endl;
        }
        return 0;
}

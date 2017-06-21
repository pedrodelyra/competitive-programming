#include <bits/stdc++.h>

using namespace std;

int changes(vector<int>& a, int i) {
        return i != a[i] ? swap(a[i], a[a[i]]), changes(a, i) + 1 : 0;
}

int main() {
        int n;
        while(cin >> n, n) {
                vector<int> a(1024);
                for(int i = 1; i <= n; ++i) {
                        cin >> a[i];
                }
                int count = 0;
                for(int i = 1; i <= n; ++i) {
                        if(i != a[i])
                                count += changes(a, i);
                }
                cout << (count & 1 ? "Marcelo" : "Carlos") << endl;
        }
        return 0;
}

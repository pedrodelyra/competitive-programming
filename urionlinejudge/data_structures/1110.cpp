#include <bits/stdc++.h>

using namespace std;

int main() {
        int n;
        while(scanf("%d", &n), n) {
                queue<int> q;
                for(int i = 1; i <= n; ++i)
                        q.push(i);
                vector<int> discarded;
                while(q.size() >= 2) {
                        discarded.push_back(q.front()); q.pop();
                        q.push(q.front()); q.pop();
                }
                printf("Discarded cards:");
                for(int i = 0; i < n - 1; ++i) {
                        printf(" %d%c", discarded[i], ",\n"[i == n - 2]);
                }
                printf("Remaining card: %d\n", q.front());
        }
        return 0;
}

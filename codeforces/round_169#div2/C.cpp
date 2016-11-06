#include <bits/stdc++.h>

#define MAX 200005

using namespace std;
using ii = pair<int, int>;
using lld = long long int;

int A[MAX];
lld fenwick[MAX];

void update(int idx, int value, int n) {
	while(idx and idx <= n) {
		fenwick[idx] += value;
		idx += idx & -idx;
	}
}

lld query(int idx) {
	lld sum = 0;
	while(idx) {
		sum += fenwick[idx];
		idx -= idx & -idx;
	}
	return sum;
}

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	priority_queue<lld> pq, frequences;
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &A[i]);
		pq.push(A[i]);
	}
	vector<ii> queries;
	while(k--) {
		int l, r;
		scanf("%d %d", &l, &r);
		update(l, 1, n);
		update(r + 1, -1, n);
		queries.push_back(ii(l, r));
	}
	for(int i = 1; i <= n; ++i) {
		frequences.push(query(i));
	}
	lld sum = 0;
	while(not frequences.empty() and not pq.empty()) {
		auto i = frequences.top(), x = pq.top();;
		sum += i * x;
		frequences.pop(), pq.pop();
	}
	printf("%lld\n", sum);
	return 0;
}

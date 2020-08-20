#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int N = 2e5 + 2;
int d[N];
LL a[N];
std::vector<int> ans1;
std::vector<int> ans2;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	Diagram D(n);
	for (int i = 1, x; i <= n; ++i) {
		std::cin >> x;
		if (x != -1) {
			D.addedge(i, x);
			++d[x];
		}
	}
	std::set<int> q;
	for (int i = 1; i <= n; ++i) {
		if (d[i] == 0) q.insert(i);
	}
	LL r = 0;
	while (!q.empty()) {
		int u = *q.begin();
		q.erase(q.begin());
		if (a[u] >= 0) ans1.emplace_back(u);
		else ans2.emplace_back(u);
		for (int i = D.head[u]; ~i; i = D.nxt[i]) {
			if (--d[D.to[i]] == 0) q.insert(D.to[i]);
			if (a[u] >= 0) a[D.to[i]] += a[u];
		}
		r += a[u];
	}
	std::cout << r << std::endl;
	for (auto &x : ans1) {
		std::cout << x << " ";
	}
	for (int i = ans2.size() - 1; ~i; --i) {
		std::cout << ans2[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
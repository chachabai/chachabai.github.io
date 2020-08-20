#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	std::sort(a, a + n);
	int id = 0;
	while (id < n  && a[id] <= m) {
		m -= a[id];
		++id;
	}
	print(id);
	return 0;
}
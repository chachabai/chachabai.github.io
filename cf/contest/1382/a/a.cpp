#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n, m;
		std::cin >> n >> m;
		int a[1003]={};
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			++a[x];
		}
		int r = -1;
		for (int i = 0, x; i < m; ++i) {
			std::cin >> x;
			if (a[x]) r = x;
		}
		if (r == -1) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n";
			std::cout << 1 << " " << r << std::endl;
		}
	}
	return 0;
}
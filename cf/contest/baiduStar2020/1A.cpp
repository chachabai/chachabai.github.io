#include <bits/stdc++.h>
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n, m;
		std::cin >> n >> m;
		int r = 1e9+2;
		for (int i = 0, x, y; i < n; ++i) {
			std::cin >> x >> y;
			r = std::min(r, (m + x - 1) / x * y);
		}
		std::cout<< r <<std::endl;
	}
	return 0;
}
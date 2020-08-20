#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		int w[102] = {};
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			++w[x];
		}
		int r = 0;
		for (int i = 2; i <= 100; ++i) {
			int t = 0;
			for (int j = 0; 2 * j <= i; ++j) {
				if (2 * j == i) t += w[j] / 2;
				else t += std::min(w[j], w[i - j]);
			}
			r = std::max(r, t);
		}
		print(r);
	}
	return 0;
}
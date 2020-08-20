#include <bits/stdc++.h>

int main() {
	//freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		bool v[n + 1] = {};
		std::vector<int> p;
		for (int i = 0, x; i < 2 * n; ++i) {
			std::cin >> x;
			if (v[x]) p.emplace_back(x);
			else v[x] = true;
		}
		for (auto &x : p) std::cout << x << " ";
		std::cout << std::endl;
	}
	return 0;
}
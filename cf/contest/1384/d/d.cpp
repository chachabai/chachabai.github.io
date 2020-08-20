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
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (auto &x : a) std::cin >> x;
		int sum = 0;
		for (auto &x : a) sum ^= x;
		if (sum == 0) {
			std::cout << "DRAW\n";
		} else {
			int k = std::__lg(sum);
			int cnt = 0;
			for (auto &x : a) if((x >> k) & 1) ++cnt;
			if (cnt % 4 == 1 || (n - cnt) % 2 == 1) {
				std::cout << "WIN\n";
			} else {
				std::cout << "LOSE\n";
			}
		}
	}
	return 0;
}
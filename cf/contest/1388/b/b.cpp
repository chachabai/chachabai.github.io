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
		int t = 1 + (n - 1)/4;
		for (int i = t; i < n; ++i) std::cout << 9;
		for (int i = 0; i < t; ++i) std::cout << 8;
		std::cout << std::endl;
	}
	return 0;
}
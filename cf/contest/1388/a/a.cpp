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
		if (n >= 31) {
			std::cout << "YES\n";
			n -= 30;
			if (n == 6 || n == 10 || n == 14) {
				std::cout << "6 10 15 " << n - 1 << std::endl;
			} else {
				std::cout << "6 10 14 " << n << std::endl;
			}
		} else std::cout << "NO\n";
	}
	return 0;
}
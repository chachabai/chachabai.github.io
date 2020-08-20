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
		int a[n];
		for (int i = 0; i < n; ++ i) {
			std::cin >> a[i];
		}
		std::string x(102,'a');
		std::cout << x << std::endl;
		auto next = [](char x) -> char {
			return (x - 'a' + 1)%26 + 'a';
		};
		for (int i = 0; i < n; ++i) {
			x[a[i]] = next(x[a[i]]);
			std::cout << x << std::endl;
		}
	}
	return 0;
}
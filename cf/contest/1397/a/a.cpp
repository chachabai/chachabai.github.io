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
		int c[26] = {};
		for (int i = 0; i < n; ++i) {
			std::string s;
			std::cin >> s;
			for (auto &x : s) ++c[x - 'a'];
		}
		bool flag = 1;
		for (int i = 0; i < 26; ++i) if (c[i] % n) flag = 0;
		std::cout << (flag ? "YES" : "NO") << std::endl;
	}
	return 0;
}
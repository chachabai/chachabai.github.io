#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int l = 1, r = 1e6;
	while (l <= r) {
		int m = (l + r) / 2;
		std::cout << m << std::endl;
		std::string s;
		std::cin >> s;
		if (s[0] == '<') r = m - 1;
		else l = m + 1;
	}
	std::cout << "! " << r << std::endl;
	return 0;
}
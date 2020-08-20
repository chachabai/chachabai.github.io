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
		std::string a, b;
		std::cin >> n >> a >> b;
		a += '0'; b += '0';
		std::vector<int> qa, qb;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != a[i-1]) qa.emplace_back(i);
			if (b[i] != b[i-1]) qb.emplace_back(i);
		}
		qa.insert(qa.end(), qb.rbegin(), qb.rend());
		std::cout << qa.size();
		for (auto &x : qa) std::cout << " " << x;
		std::cout << std::endl;
	}
	return 0;
}
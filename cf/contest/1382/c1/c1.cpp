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
		std::vector<int> q;
		while (--n >= 0) {
			if(a[n] != b[n]) {
				q.emplace_back(n + 1);
				q.emplace_back(1);
				q.emplace_back(n + 1);
			}
		}
		std::cout << q.size();
		for (auto &x : q) std::cout << " " << x;
		std::cout << std::endl;
	}
	return 0;
}
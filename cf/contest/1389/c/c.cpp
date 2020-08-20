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
		std::string a;
		std::cin >> a;
		std::vector<std::string> q;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				std::string t;
				for (auto &x : a) {
					if (x == '0' + i || x == '0' + j) t.push_back(x);
				}
				if(t.size()) q.push_back(t);
			}
		}
		auto f = [](std::string x) {
			int r = std::count(x.begin(), x.end(), x[0]);
			r = std::max(r, int(x.length()) - r);
			int cnt = 1;
			for (int i = 1; i != x.size(); ++i) {
				if (x[i] != x[i - 1]) ++cnt;
			}
			return std::max(r, cnt/2*2);
		};
		int r = 0;
		for (auto &x : q) {
			r = std::max(r, f(x));
		}
		std::cout << a.size() - r << std::endl;
	}
	return 0;
}
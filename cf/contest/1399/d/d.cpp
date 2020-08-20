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
		std::string s;
		std::cin >> n >> s;
		int k = 0, r[n];
		std::stack<int> id[2];
		for (int i = 0; i < n; ++i) {
			int t = ('0' == s[i]);
			if (id[t].size()) {
				r[i] = id[t].top();
				id[t].pop();
			} else {
				r[i] = ++k;
			}
			id[1 - t].push(r[i]);
		}
		print(k);
		for (int i = 0; i < n; ++i) std::cout << r[i] << " ";
		std::cout << std::endl;
	}
	return 0;
}
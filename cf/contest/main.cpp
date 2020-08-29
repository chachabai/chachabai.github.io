#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int d, t, s;
	std::cin >> d >> t >> s;
	std::cout << (d <= t * s ? "Yes" : "No") << std::endl;
	return 0;
}
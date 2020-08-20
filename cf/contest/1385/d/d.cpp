#include<bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

int main(){
	//freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	std::cin>>cas;
	while(cas--){
		int n;
		std::string a;
		std::cin >> n >> a;
		std::vector<int> q(n);
		for (int i = 0; i != n; ++i) q[i] = a[i]-'a';
		std::function<int(int, int, int)> f = [&](int l, int r, int d) -> int{
			if (l == r) return q[l] != d;
			int m = (l + r) / 2, c1 = 0, c2 = 0;
			for (int i = l; i <= m; ++ i) if (q[i] != d) ++c1;
			for (int i = r; i > m; --i) if (q[i] != d) ++c2;
			return std::min(c1 + f(m + 1, r, d + 1), c2 + f(l, m, d + 1));
		};
		std::cout << f(0,n-1,0) << std::endl;
	}
	return 0;
}
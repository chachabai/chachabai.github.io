#include<bits/stdc++.h>

int main(){
	//freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	std::cin>>cas;
	while(cas--){
		int n;
		std::cin >> n;
		std::vector<int> q(n);
		for (auto &x : q) std::cin >> x;
		int r = n-1;
		while (r > 0 && q[r] <= q[r-1]) --r;
		while (r > 0 && q[r] >= q[r-1]) --r;
		std::cout << r << std::endl;
	}
	return 0;
}
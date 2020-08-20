#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int cas;
	cin >> cas;
	while (cas--) {
		int n;
		cin >> n;
		int p[n];
		for(int i=0, x; i<n; ++i) {
			cin >> x;
			p[x-1]=i;
		}
		int l = 0, r = n-1;
		while(l<r && p[l]==l) ++l;
		while(r>l && p[r]==r) --r;
		bool flag = 0;
		if(l==r){
			 cout<<0<<endl;continue;
		}
		for(int i=l;i<=r;++i){
			if(p[i]==i){
				flag = 1;
				break;
			}
		}
		cout<<(flag?2:1)<<endl;
	}
	return 0;
}


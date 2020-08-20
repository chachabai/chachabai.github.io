#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int n;
	cin >> n;
	int nn = n/2;
	LL a[n], s = 0,r = 0, ans = 0;
	for (int i=0; i < n; ++i){
		cin >> a[i];
		s += a[i];
	}
	for(int i=0;i<nn;++i){
		r+=a[i*2];
	}
	ans = s - r;
	for(int i = nn*2-2; i>=0; i-=2) {
		r+=a[i+1]-a[i];
		ans = max(ans,s-r);
	}
	for (int i=nn*2-1;i>0;i-=2) {
		r+=a[i+1]-a[i];
		ans = max(ans,s-r);
	}
	cout<<ans<<endl;
	return 0;
}


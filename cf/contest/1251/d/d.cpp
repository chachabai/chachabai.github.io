#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	while(cas--){
		int n;
		LL s;
		cin>>n>>s;
		pair<LL,LL> a[n];
		LL r=1,l=1e9+2;
		for(int i=0;i<n;++i){
			cin>>a[i].first>>a[i].second;
			l = min(l,a[i].first);
			r = max(r,a[i].second);
			s-=a[i].first;
		}
		sort(a,a+n);
		auto f = [&](LL x){
			int id = lower_bound(a,a+n,make_pair(x,x))-a;
			int now = n-id;
			LL cost=0;
			while(id>0&&now<=n/2){
				if(a[--id].second>=x){
					cost+=(x-a[id].first);
					if(cost<=s) ++now;
					else break;
				}
			}
			return now > n/2;
		};
		while(l<=r){
			LL mid = (l+r)/2;
			if(f(mid)) l = mid+1;
			else r = mid-1;
		}
		cout<<r<<endl;
	}
	return 0;
}


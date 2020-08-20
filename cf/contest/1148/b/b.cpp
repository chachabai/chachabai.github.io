#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n,m,ta,tb,k;
	cin>>n>>m>>ta>>tb>>k;
	int a[n],b[m];
	for(int i=0;i<n;++i){
		cin>>a[i];
		a[i]+=ta;
	}
	for(int i=0;i<m;++i) cin>>b[i];
	if(n<=k||m<=k){
		cout<<-1<<endl;
	}else{
		int ans = 0;
		for(int i=0;i<=k;++i){
			int id = lower_bound(b,b+m,a[i])-b;
			if(id+k-i>=m){
				ans = -1;break;
			}
			ans = max(ans,tb+b[id+k-i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}


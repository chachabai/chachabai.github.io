#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n;
	cin>>n;
	LL a[n];
	for(int i=0;i<n;++i) cin>>a[i];
	sort(a,a+n);
	LL b[n]={LL(2e18)};
	for(int i=1;i<n;++i) b[i] = a[i]-a[i-1];
	sort(b,b+n);
	LL s[n+1]={0};
	for(int i=1;i<=n;++i) s[i]=s[i-1]+b[i-1];
	auto f = [&](LL len) -> LL{
		int id = upper_bound(b,b+n,len)-b;
		//cout<<id<<" "<<b[id]<<" "<<len<<endl;
		return s[id]+(len+1)*(n-id);
	};
	int q;
	cin>>q;
	while(q--){
		LL l,r;
		cin>>l>>r;
		cout<<f(r-l)<<" ";
	}
	cout<<endl;
	return 0;
}
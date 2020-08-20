// https://www.luogu.com.cn/problem/T135246?contestId=28195
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const LL M = 998244353;
LL powmod(LL x,LL n){
	LL r = 1;
	while(n){
		if(n&1) r=r*x%M;
		n>>=1;  x=x*x%M;
	}
	return r;
}
int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	LL a[n+1];
	for(int i=1;i<=n;++i) cin>>a[i];
	while(m--){
		int q,l,r,y,z;
		cin>>q;
		if(q==1){
			LL x;
			cin>>l>>r>>x;
			for(int i=l;i<=r;++i){
				a[i] = powmod(a[i],x);
			}
		}else if(q==2){
			cin>>l>>r>>y;
			LL t = a[y];
			for(int i=l;i<=r;++i){
				a[i]=a[i]*t%M;
			}
		}else{
			cin>>z;
			cout<<a[z]<<endl;
		}
		for(int i=1;i<=n;++i){
			cout<<a[i]<<" \n"[i==n];
		}
	}
	return 0;
}
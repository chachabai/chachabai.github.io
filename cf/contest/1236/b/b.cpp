#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl
constexpr LL M = 1e9+7;
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
	LL n,m;
	cin>>n>>m;
	cout<<powmod(powmod(2,m)-1,n)<<endl;
	return 0;
}


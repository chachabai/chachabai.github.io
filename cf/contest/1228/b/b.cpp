#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl
constexpr LL M = 1000000007;
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
	int h,w;
	cin>>h>>w;
	int a[h][w]={},b[h][w]={};
	for(int i=0,x;i<h;++i){
		cin>>x;
		for(int j=0;j<x;++j){
			a[i][j]=1;
		}
		if(x<w) a[i][x] = -1; 
	}
	for(int j=0,x;j<w;++j){
		cin>>x;
		for(int i=0;i<x;++i) b[i][j]=1;
		if(x<h) b[x][j] = -1;
	}
	LL r = 0;
	for(int i=0;i<h;++i){
		for(int j=0;j<w;++j){
			if(a[i][j]*b[i][j]==-1){
				cout<<0<<endl;
				return 0;
			}
			if(a[i][j]==0&&b[i][j]==0) ++r;
		}
	}
	cout<<powmod(2LL,r)<<endl;
	return 0;
}


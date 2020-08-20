// https://www.luogu.com.cn/problem/T135246?contestId=28195
#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	LL a[n][m],dp[n][m],s[n][m],r[n+1][m];
	for(int i=0;i<n;++i){
		int cur = 0;
		for(int j=0;j<m;++j){
			cin>>a[i][j];
			if(j==0) s[i][j] = a[i][j];
			else s[i][j] = s[i][j-1]+a[i][j];
			cur += a[i][j];
			dp[i][j] = cur;
			cur = min(cur,0);
		}
	}
	for(int i=n-1;i>=0;--i){
		LL mi = 1e9+2;
		for(int j=m-1;j>=0;--j){
			r[i][j] = (i==n-1?0:r[i+1][j]);
			if(r[i][j]<mi-s[i][j]){
				mi = r[i][j]+s[i][j]; 
			}else{
				r[i][j] = mi-s[i][j];
			}
		}
		for(int j=0;j<m;++j){
			r[i][j] += dp[i][j];
		}
	}
	LL ret = r[0][0];
	for(int j=1;j<m;++j){
		ret = min(ret,r[0][j]);
	}
	cout<<ret<<endl;
	return 0;
}
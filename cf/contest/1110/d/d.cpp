#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cnt,m;
	cin>>cnt>>m;
	int c[m+1]={};
	for(int i=0,x;i<cnt;++i){
		cin>>x;
		++c[x];
	}
	int dp[3][3],new_dp[3][3];
	memset(dp,-1,sizeof(dp));
	dp[0][0] = 0;
	for(int n=0;n<m;++n){
		memset(new_dp,-1,sizeof(new_dp));
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				for(int k=0;k<3;++k){
					if(i+j+k<=c[n+1]&&dp[i][j]>=0){
						new_dp[j][k] = max(new_dp[j][k],dp[i][j]+i+(c[n+1]-i-j-k)/3);
					}
				}
			}
		}
		swap(new_dp,dp);
	}
	cout<<dp[0][0]<<endl;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl
constexpr int N = 20;
LL cnt[N][N],s[N],dp[1<<N];

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=0,x;i<n;++i){
		cin>>x;--x;
		for(int j=0;j<N;++j) if(x!=j){
			cnt[x][j] += s[j];
		}
		++s[x];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=0;i!=(1<<N);++i){
		for(int j=0;j<N;++j) if(!(i&(1<<j))){
			LL s = dp[i];
			for(int k=0;k<N;++k) if(i&(1<<k)){
				s+=cnt[j][k];
			}
			dp[i|(1<<j)] = min(dp[i|(1<<j)],s);
		}
	}
	cout<<dp[(1<<N)-1]<<endl;
	return 0;
}


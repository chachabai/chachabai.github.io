#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 502;
int a[N][N];
bool f(int n,int m){
	for(int i=1;i<=n;++i){
		int cnt = 0;
		for(int j=1;j<=m;++j){
			if(a[i][j]){
				++cnt;
				if(i!=n){
					a[i+1][j]^=a[i][j];
				}
			}
		}
		if(cnt&1) return false;
		if(i==n) return cnt==0;
	}
}
int main(){
	//freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1,x;j<=m;++j){
			cin>>x;
			a[i][j]^=x;
		}
	}
	cout<<(f(n,m)?"Yes":"No")<<endl;
	return 0;
}
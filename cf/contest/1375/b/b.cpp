#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	//freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	while(cas--){
		int n,m;
		cin>>n>>m;
		int a[n+1][m+1],b[n+1][m+1]={};
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>a[i][j];
				b[i][j] = 2+int(i!=1&&i!=n)+int(j!=1&&j!=m);
			}
		}
		bool flag = true;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]>b[i][j]){
					flag = false;
					break;
				}
			}
		}
		if(flag){
			cout<<"YES"<<endl;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					cout<<b[i][j]<<" \n"[j==m];
				}
			}
		}else cout<<"NO"<<endl;
	}
	return 0;
}


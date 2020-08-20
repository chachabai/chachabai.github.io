#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	while(cas--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0,x;i<n;++i){
			cin>>x;
			a[i] = x<0?-x:x;
			if(i&1) a[i]=-a[i];
		}
		for(int i=0;i<n;++i){
			cout<<a[i]<<" \n"[i==n-1];
		}
	}
	return 0;
}


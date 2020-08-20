#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	while(cas--){
		int n;
		cin>>n;
		string a[n];
		for(int i=0;i<n;++i) cin>>a[i];
		int cnt=0,odd=0;
		for(int i=0;i<n;++i){
			for(auto &x:a[i]){
				if(x=='1') ++cnt;
			}
			if(a[i].size()&1) ++odd;
		}
		if(odd>0||cnt%2==0) cout<<n<<endl;
		else cout<<n-1<<endl;
	}
	return 0;
}


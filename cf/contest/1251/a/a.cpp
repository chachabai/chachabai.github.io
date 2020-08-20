#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	while(cas--){
		string a;
		cin>>a;
		int n = a.length();
		bool v[26]={};
		for(int i=0;i<n;++i){
			if(i==n-1){
				v[a[i]-'a'] = 1;
			}else{
				if(a[i]==a[i+1]) ++i;
				else v[a[i]-'a'] = 1; 
			}
		}
		for(int i=0;i<26;++i){
			if(v[i]) cout<<char('a'+i);
		}
		cout<<endl;
	}
	return 0;
}


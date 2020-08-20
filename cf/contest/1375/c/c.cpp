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
		for(int i=0;i<n;++i) cin>>a[i];
		int l = 0,r = n-1;
		while(l<r&&a[l]<=a[l+1]){
			++l;
			a[l] = a[l-1];
		}
		while(r>l&&a[r]>=a[r-1]){
			--r;
			a[r] = a[r+1];
		}
		cout<<(l==r||a[l]<a[r]?"YES":"NO")<<endl;
	}
	return 0;
}


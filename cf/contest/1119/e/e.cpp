#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n;
	cin>>n;
	LL r=0,cur=0,x;
	for(int i=0;i<n;++i){
		cin>>x;
		if(x>=cur*2){
			r+=cur;
			x-=cur*2;
			cur = x%3;
			r+=x/3;
		}else{
			cur-=x/2;
			cur+=x%2;
			r+=x/2;
		}
	}
	cout<<r<<endl;
	return 0;
}


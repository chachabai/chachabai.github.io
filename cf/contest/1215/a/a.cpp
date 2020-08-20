#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int a1,a2,k1,k2,n;
	cin>>a1>>a2>>k1>>k2>>n;
	if(k1>k2){
		swap(k1,k2);swap(a1,a2);
	}
	int x = n-a1*(k1-1)-a2*(k2-1);
	cout<<max(x,0)<<" ";
	if(n>k1*a1){
		cout<<a1+(n-k1*a1)/k2<<endl;
	}else cout<<n/k1<<endl;
	return 0;
}


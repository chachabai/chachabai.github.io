#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e8+2;
int p[N],pi[N];
bool isp[N];
int initprime(){
    int cnt=1;p[1]=2;isp[2] = true;
    for(int i=3;i<N;i+=2)   isp[i]=true;
    for(int i=3;i<N;i+=2){
        if(isp[i])  p[++cnt] = i;
        for(int j = 2,t=(N-1)/i + 1;j <= cnt && p[j] < t; ++j){
            isp[i * p[j]] = false;
            if(i%p[j] == 0) break;
        }
    }
    return cnt;
}
const int M = 7;
const int PM = 2*3*5*7*11*13*17;
int phi[PM+1][M+1],sz[M+1];
void init(){
    initprime();
    pi[2] = 1;
    for(int i=3;i<N;++i){
        if(isp[i])  pi[i]=pi[i-1]+1;
        else  pi[i]=pi[i-1];
    }
    sz[0]=1;
    for(int i=0;i<=PM;++i)  phi[i][0]=i;
    for(int i=1;i<=M;++i){
        sz[i]=p[i]*sz[i-1];
        for(int j=1;j<=PM;++j){
            phi[j][i]=phi[j][i-1]-phi[j/p[i]][i-1];
        }
    }
}
LL primepi(LL x);
LL primephi(LL x, int s){
    if(s <= M)  return phi[x%sz[s]][s]+(x/sz[s])*phi[sz[s]][s];
    if(x/p[s] <= p[s])  return primepi(x)-s+1;
    if(x<N && x/p[s]/p[s] <= p[s]){
        int s2x = pi[(int)(sqrt(x+0.2))];
        LL ans = pi[x]-LL(s2x+s-2)*(s2x-s+1)/2;
        for(int i=s+1;i<=s2x;++i){
            ans+=pi[x/p[i]];
        }
        return ans;
    }
    return primephi(x,s-1)-primephi(x/p[s],s-1);
}
LL primepi(LL x){
    if(x<N) return pi[x];
    int ps2x = pi[int(sqrt(x+0.2))];
    int ps3x = pi[int(cbrt(x+0.2))];
    LL ans = primephi(x,ps3x) + LL(ps2x+ps3x-2)*(ps2x-ps3x+1)/2;
    for(int i =ps3x+1,ed = ps2x;i<=ed;++i){
        ans -= primepi(x/p[i]);
    }
    return ans;
}

int main(){
    init();
    LL n;
    while(cin>>n){ // n=98765432109876 = 9.8*10^13 用时 38s, N 大点，耗时会小点
        time_t now = time(0);
        cout<<primepi(n)<<endl;
        cout<<"Time used: "<<difftime(time(0),now)<<endl;
    }
    return 0;
}
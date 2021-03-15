#include <iostream>
#include <memory.h>

using namespace std;

int N,cache[101][101];

int solve(int n,int pre){
    if(n<=0)return 0;if(n==1)return 1;
    int &ret=cache[n][pre];if(ret!=-1)return ret;ret=0;
    if(pre==0)for(int i=1;i<=n;i++){
        ret+=solve(n-i,i);ret%=10000000;
    }
    else for(int i=1;i<=n;i++){
        ret+=(solve(n-i,i)*(pre+i-1))%10000000;ret%=10000000;
    }
    return ret;
}

int main(){
    int C;cin>>C;memset(cache,-1,sizeof(cache));
    while(C--){
        cin>>N;cout<<solve(N,0)<<endl;
    }
}
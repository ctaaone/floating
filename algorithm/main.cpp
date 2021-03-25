#include <iostream>
#include <memory.h>
#include <string>

using namespace std;


int N,M,K;int cache[101][101];int INF = 1e9+1;

int solve(int n, int m){
    int &ret = cache[n][m]; if(ret != -1)return ret;
    if(n==0 && m==0)return ret = 1;
    if(n==0) return ret = solve(0,m-1);
    if(m==0) return ret = solve(n-1,0);
    int temp=(solve(n-1,m) + solve(n,m-1));
    return ret = temp>INF?INF:temp;
}

string getR(int n, int m, int k){
    string ret;
    if(n==0) {for(int i=0;i<m;i++){ret = ret + "o";}return ret;};
    if(m==0) {for(int i=0;i<n;i++){ret = ret + "-";}return ret;};
    if(k <= solve(n-1,m)){
        return ret = "-" + getR(n-1,m,k);
    }
    else{
        return ret = "o" + getR(n,m-1,k-solve(n-1,m));
    }
}

int main(){
    int C;cin>>C;memset(cache,-1,sizeof(cache));
    while(C--){
        cin>>N>>M>>K;
        cout<<getR(N,M,K)<<endl; 
    }
    return 0;
}
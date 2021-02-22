#include <iostream>
#include <memory.h>

using namespace std;

int N,M,A[101],B[101],cache[101][101];

int max(int&a,int&b){
    return a>b?a:b;
}

int solve(int a,int b){
    if(a==N&&b==M){
        if(A[a]==B[b])return 1;return 2;
    }
    int ret=cache[a][b],ma=0;
    if(ret!=-1)return ret;
    for(int i=a+1;i<=N;i++){
        if(A[i]>A[a]&&A[i]!=B[b])ma=max(solve(i,b)+1,ma);
    }
    for(int j=b+1;j<=M;j++){
        if(B[j]>B[b]&&B[j]!=A[a])ma=max(ma,solve(a,j)+1);
    }

}

int main(){
    int C;cin>>C;
    while(C--){
        cin>>N>>M;
        for(int i=1;i<=N;i++)cin>>A[i];
        for(int i=1;i<=M;i++)cin>>B[i];
        memset(cache,-1,sizeof(cache));
        cout<<solve(0,0)-1<<endl;
    }
    return 0;
}
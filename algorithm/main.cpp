#include <iostream>
#include <memory.h>

using namespace std;

int N,M,A[101],B[101],cache[101][101];

int max(int&a,int&b){
    return a>b?a:b;aaaaa
}

int solve(int a,int b){
    int ret=cache[a][b],ma=0;
    if(ret!=-1)return ret;
    for(int i=a+1;i<=N;i++){
        for(int j=b+1;j<=M;j++){
            if()ma=max(ma,solve(i,j));
        }
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
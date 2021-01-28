#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define FOR(i,N) for(int (i)=0;(i)<(N);(i++))

int arr[10][10],count;

int solve(int n,vector<int>& isPair){
    
    for(int i=n+1;i<10;i++){
        if(arr[n][i]){
            isPair[n]=1;
            isPair[i]=1;
            for(int j=0;j<10;j++){
                if(isPair[j]==0){
                    solve(j,isPair);
                }
            }
        }
    }

}

int main(){

    int C, N, M;vector<int> isPair(10);
    int a,b;
    scanf("%d",&C);
    while(C--){
        FOR(i,10)FOR(j,10)arr[i][j]=0;
        FOR(i,10)isPair[i]=0; count=0;
        scanf("%d%d",&N,&M);
        FOR(i,M){
            scanf("%d%d",&a,&b);
            arr[a][b]=1;arr[b][a]=1;
        }
        solve(0,isPair);
        printf("%d\n",count);
    }

}
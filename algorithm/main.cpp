#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define FOR(i,N) for(int (i)=0;(i)<(N);(i++))

int arr[10][10],count,Num;

void solve(int n,vector<int>& isPair){
    int flag=0;
    for(int i=n+1;i<Num;i++){
        if(arr[n][i]&&isPair[i]==0){
            isPair[n]=isPair[i]=1;
            FOR(j,Num)if(!isPair[j])flag=1;if(!flag)count++;
            for(int j=n+1;j<Num;j++)
                if(!isPair[j]){solve(j,isPair);break;}
            isPair[i]=0;
        }
    }
    isPair[n]=0;
}

int main(){

    int C, M;vector<int> isPair(10);
    int a,b;
    scanf("%d",&C);
    while(C--){
        FOR(i,10)FOR(j,10)arr[i][j]=0;
        FOR(i,10)isPair[i]=0; count=0;
        scanf("%d%d",&Num,&M);
        FOR(i,M){
            scanf("%d%d",&a,&b);
            arr[a][b]=1;arr[b][a]=1;
        }
        solve(0,isPair);
        printf("%d\n",count);
    }

}
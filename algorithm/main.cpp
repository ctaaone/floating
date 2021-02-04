#include <stdio.h>
#include <vector>

using namespace std;

#define FOR(i,n) for(int i=0;i<(n);i++)
#define INF 99999


vector<int> clock;
int swi[10][5]={
    {0,1,2,-1,-1},
    {3,7,9,11,-1},
    {4,10,14,15,-1},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15,-1},
    {3,14,15,-1,-1},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};

int min(int a,int b){
    return a<b?a:b;
}

int solve(int n){
    int ret=INF;
    if(n==10){
        FOR(i,16){
            if(clock[i]!=0)return INF;
        }
        return 0;
    }else{
        FOR(i,4){
            ret=min(solve(n+1)+i,ret);
            FOR(j,5){
                if(swi[n][j]==-1)continue;
                clock[swi[n][j]]++;clock[swi[n][j]]%=4;
            }
        }
    }
    return ret;
}

int main(){
    int C,temp;
    scanf("%d",&C);
    while(C--){
        FOR(i,16){scanf("%d",&temp);clock.push_back(temp/3%4);}
        temp=solve(0);
        printf("%d\n",(temp==INF?-1:temp));
        FOR(i,16)clock.pop_back();
    }
    return 0;
}
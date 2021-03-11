#include <iostream>
#include <memory.h>

using namespace std;


int N,arr[100][100],cache1[100][100],cache2[100][100][100001],M;

int getMax(int x, int y){
    if(y==N-1)return arr[y][x];
    int& ret=cache1[y][x];
    if(ret!=-1)return ret;
    int a=getMax(x,y+1),b=getMax(x+1,y+1);
    if(a>b)return ret=a+arr[y][x];
    return ret=b+arr[y][x];
}
int solve(int x, int y, int sum, int num){
    int &ret=cache2[y][x][num];
    if(ret!=-1)return ret;
    if(y==N-1)return ret=(arr[y][x]==M?1:0);
    return ret=solve(x,y+1,sum+arr[y][x],num)+solve(x+1,y+1);
}

int main(){
    int C;cin>>C;
    while(C--){
        cin>>N;
        for(int i=0;i<N;i++)for(int j=0;j<=i;j++)cin>>arr[i][j];
        memset(cache1, -1, sizeof(cache1));memset(cache2, -1, sizeof(cache2));
        M=getMax(0,0);
        cout<<solve(0,0)<<endl;
    }
}
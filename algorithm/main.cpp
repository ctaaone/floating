#include <iostream>

using namespace std;

int cache[2][50][50];
int INF = 2e9, N, arr[50];

int solve(int t, int s, int e){ // [, ]
    
}

int main(){
    int C;cin>>C;
    while(C--){
        for(int i=0;i<2;i++)for(int j=0;j<50;j++)for(int l=0;l<50;l++)cache[i][j][l] = INF;
        cin>>N;for(int i=0;i<N;i++)cin>>arr[i];
        solve(0, 0, N-1);
        cout<<cache[0][0][N-1]<<endl;
    }
    return 0;
}
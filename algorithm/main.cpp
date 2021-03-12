#include <iostream>
#include <memory.h>

using namespace std;


int N,M;double cache[2001][1000];

double solve(int sum, int n){
    double &ret=cache[sum][n];
    if(ret!=-1)return ret;
    if(n==M-1)return ret=(sum+1>=N?0.25:0)+(sum+2>=N?0.75:0);
    return ret=(solve(sum+1,n+1)*0.25+solve(sum+2,n+1)*0.75);
}

int main(){
    int C;cin>>C;
    while(C--){
        cin>>N>>M;for(int i=0;i<2001;i++)for(int j=0;j<1000;j++)cache[i][j]=-1;
        printf("%.10lf\n",solve(0,0));
    }
}
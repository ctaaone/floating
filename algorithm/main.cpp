#include <iostream>
#include <memory.h>

using namespace std;


int N,arr[501]={-1},cache[501];

int max(int &a, int &b){
    return a>b?a:b;
}

int solve(int index){
    int &ret=cache[index];
    if(ret!=-1)return ret;
    int ma=1;
    for(int i=index+1;i<=N;i++)
        if(arr[index]<arr[i])ma=max(ma, solve(i)+1);
    return ret=ma;
}

int main(){
    int C;cin>>C;
    while(C--){
        cin>>N;int ma=0;
        for(int i=1;i<=N;i++)cin>>arr[i];
        memset(cache, -1, sizeof(cache));
        cout<<solve(0)-1<<"\n";
    }
    return 0;
}
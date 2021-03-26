#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int N,K,arr[501]={0},cache[501];
int count[501];

int max(int &a, int &b){
    return a>b?a:b;
}

int getLIS(int n){ //count from 1
    int &ret = cache[n]; if(ret != -1)return ret;
    if(n==N)return ret = 1;
    for(int i=n+1;i<=N;i++){
        if(arr[n]<arr[i])
        ret = max(ret, getLIS(i) + 1);
    }
    for(int i=n+1;i<=N;i++)
        if(ret == cache[i] + 1)count[i]+=1;
    return ret;
}

int getC(int in){

    return 0;
}
void pv(vector<int> &r){
    for(int i=0;i<r.size();i++)cout<<r[i]<<" ";cout<<endl;
}
int main(){
    int C;cin>>C;
    while(C--){
        cin>>N>>K;memset(cache, -1, sizeof(cache));memset(count, 0, sizeof(count));
        for(int i=1;i<=N;i++)cin>>arr[i];
        getLIS(0);
        vector<int> r;
        getC(0);cout<<cache[0]-1<<endl;pv(r);
    }
}
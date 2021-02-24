#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;
void pa(vector<int>&a){
    for(int i=a.size()-1;i>=0;i--)cout<<a[i]<<" ";cout<<endl;
}
int min(int &a, int &b){
    return a<b?a:b;
}
int N,S,cache[100][10],cache2[1000][1000],INF=(int)2e9;
int eval(vector<int>&arr, int s, int e){
    if(e>arr.size())return INF;
    int &ret=cache2[s][e-1];if(ret!=-1)return ret;
    int mi=INF;
    for(int i=1;i<=1000;i++){
        int temp=0;
        for(int j=s;j<e;j++){
            temp+=(arr[j]-i)*(arr[j]-i);
        }mi=min(mi,temp);
    }return ret=mi;
}
int solve(vector<int>&arr, int in, int n){
    if(in>=arr.size())return 0;
    int &ret=cache[in][n];if(ret!=-1)return ret;
    if(n==0)return ret=eval(arr, in, arr.size());int mi=INF;
    for(int i=in+1;i<=arr.size();i++){
        mi=min(mi,eval(arr,in,i)+solve(arr,i,n-1));
    }
    return ret=mi;
}
int comp(int&a, int&b){
    return a>b;
}
int main(){
    int C;cin>>C;
    while(C--){
        cin>>N>>S;int temp;vector<int> arr;
        for(int i=0;i<N;i++){
            cin>>temp;arr.push_back(temp);
        }
        sort(arr.begin(), arr.end(),comp);
        memset(cache,-1,sizeof(cache));memset(cache2, -1, sizeof(cache2));
        cout<<solve(arr, 0, S-1)<<endl;
    }
    return 0;
}
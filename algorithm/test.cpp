#include <iostream>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

long long max(long long& a, long long &b){
    return a>b?a:b;
}

const long long NEGINF = -10000000000;
int n, m, A[100], B[100];
int cache[101][101];


int jlis(int indexA, int indexB){
    int& ret =cache[indexA+1][indexB+1];
    if(ret != -1)return ret;
    ret = 2;
    long long a=(indexA==-1?NEGINF:A[indexA]);
    long long b=(indexB==-1?NEGINF:B[indexB]);
    long long maxElement=max(a,b);

    for(int nextA=indexA+1;nextA<n;nextA++){
        if(maxElement<A[nextA])ret=max(ret, jlis(nextA,indexB)+1);
    }
    for(int nextB=indexB+1;nextB<m;nextB++){
        if(maxElement<B[nextB])ret=max(ret, jlis(indexA,nextB)+1);
    }
    return ret;
}

int main(){
    int C;cin>>C;
    while(C--){
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>A[i];
        for(int i=0;i<m;i++)cin>>B[i];
        memset(cache,-1,sizeof(cache));
        cout<<jlis(0,0)-1<<endl;
    }
    return 0;
}
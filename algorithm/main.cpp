#include <iostream>
#include <memory.h>

using namespace std;

int N,cache[101];

int solve(int in){
    int& ret=cache[in];if(ret!=-1)return ret;
    if(in==1)return ret=1;if(in==2)return ret=2;
    return ret=(solve(in-1)+solve(in-2))%1000000007;
}

int main(){
    int C;cin>>C;
    while(C--){
        cin>>N;memset(cache, -1, sizeof(cache));
        cout<<solve(N)<<endl;
    }
    return 0;
}
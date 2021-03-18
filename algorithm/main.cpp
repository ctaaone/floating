#include <iostream>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

int N,W,cache[1001][100];
vector<string> list;vector<int> weight;vector<int> des;vector<int> path;
int solve(int w, int in){
    if(in==N)return 0;
    int &ret=cache[w][in];if(ret!=-1)return ret;
    if(w-weight[in]<0){return ret=solve(w,in+1);}
    int a,b;
    a=solve(w-weight[in],in+1)+des[in];
    b=solve(w,in+1);
    if(a>b){path.push_back(in);return ret=a;}
    return ret=b;
}

int main(){
    int C;cin>>C;
    while(C--){
        cin>>N>>W;memset(cache,-1,sizeof(cache));
        for(int i=0;i<N;i++){
            string t1;int t2,t3;
            cin>>t1>>t2>>t3;
            list.push_back(t1);weight.push_back(t2);des.push_back(t3);
        }
        printf("%d",solve(W,0));printf(" %d\n",(int)path.size());
        while(!path.empty()){cout<<list[path.back()]<<endl;path.pop_back();}
        for(int i=0;i<N;i++){list.pop_back();weight.pop_back();des.pop_back();}
    }
}
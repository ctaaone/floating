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
    if(a>b)return ret=a;
    return ret=b;
}
void getPath(int d){
    int resw=W, resd=d;
    for(int i=0;i<N-1;i++){
        if(resw-weight[i]>=0 && cache[resw-weight[i]][i+1]==resd-des[i]){
            path.push_back(i);
            resw -= weight[i];
            resd -= des[i];
        }
    }
    if(resd>0)path.push_back(N-1);
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
        
        int temp=solve(W,0);getPath(temp);
        
        printf("%d",temp);  printf(" %d\n",(int)path.size());
        for(int i=0;i<path.size();i++)cout<<list[path[i]]<<endl;
        
        while(!path.empty())path.pop_back();
        for(int i=0;i<N;i++){list.pop_back();weight.pop_back();des.pop_back();}
    }
}
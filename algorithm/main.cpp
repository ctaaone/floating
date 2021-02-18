#include <iostream>
#include <memory.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int N;
string str,name;
int cache[100][100];
vector<string> result;

int solve(int si, int di){//source index, destination index
    if(si==str.size()&&di==name.size())return 1;
    else if(!(si<str.size()&&di<name.size())) return 0;
    int &ret=cache[si][di];
    if(ret!=-1)return ret;
    while(si<str.size()&&di<name.size()){
        if(str[si]!='*'&&str[si]!='?'){
            if(str[si]!=name[di])return 0;
            si++;di++;
        }else if(str[si]=='?'){
            si++;di++;
        }else{
            while(si+1<str.size()&&str[si+1]=='*')si++;
            for(int i=di;i<=name.size();i++){
                if(solve(si+1,i))return ret=1;
            }return ret=0;
        }
    }
    while(si<str.size()&&str[si]=='*')si++;
    if(si==str.size()&&di==name.size())return ret=1;
    return ret=0;
}
int comp(string a, string b){
    return a<b;
}
int main(){
    int C;cin>>C;
    while(C--){
        cin>>str;
        cin>>N;
        for(int i=0;i<N;i++){
            memset(cache, -1, sizeof(cache));
            cin>>name;
            if(solve(0,0))result.push_back(name);
        }
        sort(result.begin(),result.end(),comp);
        for(int i=0;i<result.size();i++)cout<<result[i]<<"\n";
        while(!result.empty())result.pop_back();
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int K,cache[1<<16][15],choice[15][15],exS[15];vector<string> str;


void order(){
    string temp;
    for(int i=0;i<K;i++){
        if(exS[i]==1)continue;
        for(int j=i+1;j<K;j++){
            if(exS[j]==1) continue;
            string a,b;
            if(str[i].size()>str[j].size()){a=str[i];b=str[j];}
            else {a=str[j];b=str[i];}
            for(int k=0;k<=a.size()-b.size();k++){
                int flag=1;
                for(int l=0;l<b.size();l++){
                    if(a[k+l]!=b[l]){flag=0;break;}
                }
                if(flag){
                    
                }
            }
        }
    }
}
int appN(int a, int b){

}
int min(int &a, int &b){
    return a<b?a:b;
}

int minLen(int used, int cur, int in){
    int &ret = cache[used][cur]; if(ret != -1)return ret;
    if(used == (1<<K) - 1)return ret = 0;
    ret = 0;int temp;
    for(int i=0;i<K;i++){
        if( ((1<<i)&used) == 1)continue;
        temp = appN(cur,i)+minLen(used|(1<<i),i,in+1);
        if(ret > temp){
            ret = temp;
            choice[in][cur] = i;
        }
    }
    return ret;
}

int main(){
    int C;cin>>C;
    while(C--){
        cin>>K;string temp;memset(cache, -1, sizeof(cache));memset(choice,-1,sizeof(choice));
        memset(exS, 0, sizeof(exS));
        for(int i=0;i<K;i++){cin>>temp;str.push_back(temp);}order();

        for(int i=0;i<K;i++)minLen(1<<i,i,0);

        while(!str.empty())str.pop_back();
    }return 0;
}
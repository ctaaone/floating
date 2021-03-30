#include <iostream>
#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int K,cache[1<<16][15],choice[15][15];vector<string> str;

void order(){
    string temp;
    for(int i=0;i<K;i++){
        temp = str[i];
        for(int j=i+1;j<K;j++)
            if(temp == str[j]){str.erase(str.begin()+j);K--;j--;}
    }
}
int appN(int a, int b){

}
int min(int &a, int &b){
    return a<b?a:b;
}

int minLen(int used, int cur){
    int &ret = cache[used][cur]; if(ret != -1)return ret;
    if(used == (1<<K) - 1)return ret = 0;
    ret = 0;int temp;
    for(int i=0;i<K;i++){
        if( ((1<<i)&used) == 1)continue;
        temp = appN(cur,i)+minLen(used|(1<<i),i);
        if(ret > temp){
            ret = temp;
        }
    }
    return ret;
}

int main(){
    int C;cin>>C;
    while(C--){
        cin>>K;string temp;memset(cache, -1, sizeof(cache));memset(choice,-1,sizeof(choice));
        for(int i=0;i<K;i++){cin>>temp;str.push_back(temp);}order();

        for(int i=0;i<K;i++)minLen(1<<i,i);

        while(!str.empty())str.pop_back();
    }return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int K,cache[1<<16][15],choice[15][15],choiceLen[15][15],maxIn;vector<string> str;


int order(){
    string temp;
    int used=0;
    for(int i=0;i<K;i++){
        if(used&(1<<i))continue;
        for(int j=i+1;j<K;j++){
            if(used&(1<<i)) break;
            if(used&(1<<j)) continue;
            
            string a,b;
            if(str[i].size()>str[j].size()){a=str[i];b=str[j];}
            else {a=str[j];b=str[i];}

            for(int k=0;k<=a.size()-b.size();k++){
                int flag=1;
                for(int l=0;l<b.size();l++){
                    if(a[k+l]!=b[l]){
                        flag=0;break;
                    }
                }
                if(flag){
                    if(str[i].size() < str[j].size()){
                        used |= (1<<i); break;
                    }
                    used |= (1<<j); break;
                }
            }
        }
    }
    return used;
}
int appN(int a, int b){
    string A = str[a], B = str[b];
    int isWrong, ret = B.size();
    for(int k=1;k<=A.size()||k<=B.size();k++){
        for(int i=0;i<k;i++)
        if(A[A.size() - k + i] != B[i]){
            isWrong = 1; break;
        }
        if(isWrong)break;
        ret--;
    }
    return ret;
}

void getPath(int used){
    int cur = 0;
    for(int i=0;i<K;i++){
        if(used&(1<<i)) continue;
        if(cache[used|(1<<cur)][cur] == -1 || cache[used|(1<<cur)][cur] + str[cur].size() > cache[used|(1<<i)][i] + str[i].size()) cur = i;
    }
    cout<<str[cur];
    used |= (1<<cur);
    cur = choice[used][cur];

    for(int i=1;i<maxIn-1;i++){
        used |= (1<<cur);
        for(int j=0;j<choiceLen[used][cur];j++)cout<<str[cur][str[cur].size() - choiceLen[used][cur] + j];
        cur = choice[used][cur];
    }
    cout<<endl;
}

int minLen(int used, int cur, int in){
    if(in>maxIn)maxIn = in;
    int &ret = cache[used][cur]; if(ret != -1)return ret;
    if(used == (1<<K) - 1)return ret = 0;
    ret = 0;int temp;
    for(int i=0;i<K;i++){
        if( ((1<<i)&used) == 1)continue;
        temp = appN(cur,i) + minLen(used|(1<<i),i,in+1);
        if(ret > temp){
            ret = temp;
            choice[in][cur] = i;
            choiceLen[in][cur] = temp - minLen(used|(1<<i), i, in+1);
        }
    }
    return ret;
}

int main(){
    int C;cin>>C;
    while(C--){
        cin>>K;string temp;memset(cache, -1, sizeof(cache));memset(choice,-1,sizeof(choice));
        memset(choiceLen, 0, sizeof(choiceLen)); maxIn = 0;
        for(int i=0;i<K;i++){cin>>temp;str.push_back(temp);}
        int used = order();

        for(int i=0;i<K;i++){if(used&(1<<i))continue; minLen(used|(1<<i),i,0);}
        getPath(used);

        while(!str.empty())str.pop_back();
    }return 0;
}
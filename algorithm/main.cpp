#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <assert.h>
#include <stdlib.h>

using namespace std;

int K,cache[1<<16][15],choice[1<<16][15],choiceLen[1<<16][15],INF = 2e9,maxIn;vector<string> str;


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
    int isMatch, ret = B.size();
    for(int k=(A.size()<B.size()?A.size():B.size());k>0;k--){
        isMatch = 1;
        for(int i=0;i<k;i++){
            if(A[A.size() - k + i] != B[i]) {isMatch = 0; break;}
        }
        if(isMatch){ret -= k;break;}
    }
    return ret;
}

void getPath(int used){
    int cur = 0;
    for(int i=0;i<K;i++){
        if(used&(1<<i)) continue;
        if(cache[used|(1<<cur)][cur] == -1 || cache[used|(1<<cur)][cur] + str[cur].size() > cache[used|(1<<i)][i] + str[i].size()) cur = i;
    }

    used |= 1<<cur;
    cout<<str[cur];
    
    //printf("#%d\n",maxIn);
    for(int i=0;i<maxIn;i++){
        int target = choice[used][cur];
        //printf("#choiceLen %d, target %d\n",choiceLen[used][cur], target);
        for(int j=0;j<choiceLen[used][cur];j++)cout<<str[target][str[target].size() - choiceLen[used][cur] + j];
        cur = choice[used][cur];
        used |= 1<<cur;
    }

    cout<<endl;
}

int minLen(int used, int cur, int in){
    if(in>maxIn)maxIn = in;
    int &ret = cache[used][cur]; if(ret != -1)return ret;
    if(used == (1<<K) - 1)return ret = 0;
    ret = INF;int temp;
    for(int i=0;i<K;i++){
        if((1<<i)&used)continue;
        temp = appN(cur,i) + minLen(used|(1<<i),i,in+1);
        if(ret > temp){
            ret = temp;
            choice[used][cur] = i;
            choiceLen[used][cur] = temp - minLen(used|(1<<i), i, in+1);
        }
    }
    //if(in == 0)printf("#%d %d\n",ret, cur);
    return ret;
}

int main(){
    int C;cin>>C;
    while(C--){
        cin>>K;string temp;memset(cache, -1, sizeof(cache));memset(choice,-1,sizeof(choice));
        memset(choiceLen, 0, sizeof(choiceLen)); maxIn = 0;
        for(int i=0;i<K;i++){cin>>temp; str.push_back(temp);}

        int used = order();
        
        for(int i=0;i<K;i++){if(used&(1<<i))continue; minLen(used|(1<<i),i,0);}

        getPath(used);
        
        while(!str.empty())str.pop_back();
    }return 0;
}
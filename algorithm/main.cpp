#include <iostream>
#include <memory.h>

using namespace std;

long long E;int M, I, cache[20][1<<15][2];
int MOD = 1e9 + 7;

int getL(int in){ //count from 1
    long long temp = E;
    while(--in!=0){
        temp/=10;
    }return temp%10;
}

int solve(int mod, int visit, int under, int in){
    int index[10]; memset(index, 0, sizeof(index));
    int &ret = cache[mod][visit][under]; if(ret != -1) return ret;
    if(visit == 1<<I-1) return ret = (((mod % M == 0)&&(under == 1)) ? 1 : 0);
    ret = 0;
    for(int i=0;i<I;i++){
        int tu = under;
        if(((1<<i)&visit)==0 && (tu==1 || getL(in)>=getL(i+1))){
            if(index[getL(i+1)]==1)continue;
            index[getL(i+1)]=1;
            if(getL(in)>getL(i+1))tu = 1;
            ret += solve((mod*10+getL(i+1))%M,(1<<i)|visit,tu,in-1);
            ret %= MOD;
        }
    }
    return ret;
}

int main(){
    int C;cin>>C;long long temp;
    while(C--){
        scanf("%lld%d",&E,&M);
        memset(cache, -1, sizeof(cache));
        temp = E;
        for(I=0;temp;temp/=10)I++;
        cout<<solve(0,0,0,I)<<endl;
    }
    return 0;
}
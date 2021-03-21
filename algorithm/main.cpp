#include <iostream>
#include <vector>
#include <string.h>
#include <memory.h>

using namespace std;

int M,Q,N;double F[500],R[500][500],C[500][500];double cache[500][101];
char oWord[500][11],word[100][11];
int path[100];


int getIn(char * str){
    for(int i=0;i<M;i++){
        if(strcmp(str,oWord[i])==0)return i;
    }
}

void getPath(){
    memset(path, -1, sizeof(path));
    int tWord=0;int cur;
    for(int i=0;i<N;i++){
        cur = getIn(word[i]);
        for(int j=0;j<M;j++){
            if(cache[tWord][i]==cache[j][i+1]*C[j][cur]*(i==0?F[j]:R[tWord][j])){
                path[i]=j;tWord=j;break;
            }
        }
    }
}


double solve(int preW, int in){
    if(in==N)return cache[preW][in]=1.0;
    if(preW==-1){
        double &ret=cache[0][in];
        double temp;int cur=getIn(word[in]);
        ret=0;
        for(int i=0;i<M;i++){
            if(F[i]==0||C[i][cur]==0)continue;
            temp=F[i]*solve(i,in+1)*C[i][cur];
            if(ret<temp){
                path[in]=i;
                ret=temp;
            }
        }
        return ret;
    }
    double &ret=cache[preW][in];if(ret!=-1)return ret;
    double temp;int cur=getIn(word[in]);
    ret=0;
    for(int i=0;i<M;i++){
        if(R[preW][i]==0||C[i][cur]==0)continue;
        temp=R[preW][i]*solve(i,in+1)*C[i][cur];
        if(ret<temp){
            if(path[in-1]==preW)path[in]=i;
            ret=temp;
        }
    }
    return ret;
}

int main(){
    cin>>M>>Q;string temp;
    for(int i=0;i<M;i++)
        scanf("%s",oWord[i]);
    for(int i=0;i<M;i++)
        scanf("%lf",&F[i]);
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++)
            scanf("%lf",&R[i][j]);
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++)
            scanf("%lf",&C[i][j]);

    while(Q--){
        scanf("%d",&N);
        for(int i=0;i<N;i++)scanf("%s",word[i]);
        for(int i=0;i<500;i++)for(int j=0;j<101;j++)cache[i][j]=-1;
        //printf("%lf\n",solve(-1,0));getPath();
        solve(-1,0);getPath();
        for(int i=0;i<N;i++)printf("%s ",oWord[path[i]]);printf("\n");
    }

    return 0;
}
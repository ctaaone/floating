#include <iostream>
#include <vector>
#include <string.h>
#include <memory.h>
#include <cmath>

using namespace std;

int M,Q,N;double F[500],R[500][500],C[500][500];double cache[500][101];
char oWord[500][11],word[100][11];
int path[100];
double INF = -1.8e100;

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
            if(C[j][cur]==2||(i==0&&F[j]==2)||(i!=0&&R[tWord][j]==2)||cache[j][i+1]==1)continue;
            if(ceil((cache[tWord][i])*10)==ceil((cache[j][i+1]+C[j][cur]+(i==0?F[j]:R[tWord][j]))*10)){
                //printf("#%d:%d  %lf %lf %lf\n",i,j,cache[tWord][i],cache[j][i+1],C[j][cur]);
                path[i]=j;tWord=j;break;
            }
        }
    }//printf("\n");
}


double solve(int preW, int in){
    if(in==N)return cache[preW][in]=0;
    if(preW==-1){
        double &ret=cache[0][in];
        double temp;int cur=getIn(word[in]);
        ret=INF;
        for(int i=0;i<M;i++){
            if(F[i]==2||C[i][cur]==2)continue;
            temp=F[i]+solve(i,in+1)+C[i][cur];
            if(ret<temp){
                ret=temp;
            }
        }
        return ret;
    }
    double &ret=cache[preW][in];if(ret!=1)return ret;
    double temp;int cur=getIn(word[in]);
    ret=INF;
    for(int i=0;i<M;i++){
        if(R[preW][i]==2||C[i][cur]==2)continue;
        temp=R[preW][i]+solve(i,in+1)+C[i][cur];
        if(ret<temp){
            ret=temp;
        }
    }
    return ret;
}

int main(){
    cin>>M>>Q;double temp;
    for(int i=0;i<M;i++)
        scanf("%s",oWord[i]);
    for(int i=0;i<M;i++){
        scanf("%lf",&temp);
        if(temp==0){F[i]=2;continue;}
        F[i]=log10(temp);
    }
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++){
            scanf("%lf",&temp);
            if(temp==0){R[i][j]=2;continue;}
            R[i][j]=log10(temp);
        }
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++){
            scanf("%lf",&temp);
            if(temp==0){C[i][j]=2;continue;}
            C[i][j] = log10(temp);
        }

    while(Q--){
        memset(path, -1, sizeof(path));
        scanf("%d",&N);
        for(int i=0;i<N;i++)scanf("%s",word[i]);
        for(int i=0;i<500;i++)for(int j=0;j<101;j++)cache[i][j]=1;
        //printf("%lf\n",solve(-1,0));getPath();
        solve(-1,0);getPath();
        for(int i=0;i<N;i++)printf("%s ",oWord[path[i]]);printf("\n");
    }

    return 0;
}
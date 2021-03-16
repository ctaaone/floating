#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int N,D,P,arr[50][50];
double p1[50],p2[50],pa[50][50];

void getpa(){
    for(int i=0;i<N;i++){
        int count=0;
        for(int j=0;j<N;j++){
            if(arr[i][j])count++;
        }
        if(count==0)continue;
        for(int j=0;j<N;j++){
            if(arr[i][j])pa[i][j]=1.0/count;
        }
    }
}
void solve(){
    for(int d=0;d<D;d++){
        for(int i=0;i<N;i++){
            if(p1[i]==0)continue;
            for(int j=0;j<N;j++){
                if(arr[i][j])p2[j]+=pa[i][j]*p1[i];
            }
        }
        for(int i=0;i<N;i++)p1[i]=p2[i];
        memset(p2,0,sizeof(p2));
    }
}

int main(){
    int C;cin>>C;
    while(C--){
        vector<int> li;int in;
        cin>>N>>D>>P;
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>arr[i][j];memset(p1,0,sizeof(p1));memset(p2,0,sizeof(p2));memset(pa,0,sizeof(pa));
        p1[P]=1;getpa();solve();
        cin>>in;
        for(int i=0;i<in;i++){
            int temp;cin>>temp;
            li.push_back(temp);
        }
        for(int i=0;i<in;i++){
            printf("%.8lf ",p1[li[i]]);
        }printf("\n");
    }
}
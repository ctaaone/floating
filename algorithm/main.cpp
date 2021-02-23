#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

int min(int &a, int &b){
    return a<b?a:b;
}
void pa(vector<int> &arr){
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";cout<<endl;
}
vector<int> strtov(char * str){
    vector<int> ret;int i=0;
    while(str[i]){
        ret.push_back(str[i++]-'0');
    }return ret;
}
int eval(int in, vector<int>& arr,int num){
    vector<int> a(arr.begin()+in, arr.begin()+in+num);
    int sub=a[1]-a[0],subflag=1;
    for(int i=1;i<a.size();i++){
        if(sub!=a[i]-a[i-1])subflag=0;
    }
    if(subflag){
        if(sub==0)return 1;
        if(sub==1||sub==-1)return 2;
        return 5;
    }
    int alt1=a[0], alt2=a[1],altflag=1;
    for(int i=0;i<a.size();i+=2)if(alt1!=a[i])altflag=0;
    for(int i=1;i<a.size();i+=2)if(alt2!=a[i])altflag=0;
    if(altflag)return 4;
    return 10;
}
int N,cache[10000],inf=9999999;
int solve(int in, vector<int>& arr){
    if(in>N)return inf;
    if(in==N)return 0;
    int &ret=cache[in];
    if(ret!=-1)return ret;
    int mi=inf;
    for(int i=3;i<=5;i++){
        mi=min(mi, eval(in,arr,i)+solve(in+i,arr));
        //printf("in%d i%d mi%d\n",in,i,mi);
    }
    return ret=mi;
}
int main(){
    int C;cin>>C;char str[10001];
    while(C--){
        scanf("%s",str);
        vector<int> arr=strtov(str);N=arr.size();memset(cache,-1,sizeof(cache));
        cout<<solve(0,arr)<<endl;
    }return 0;
}
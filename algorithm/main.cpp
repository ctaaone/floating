#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> multi(vector<int>&a, vector<int>&b){
    if(a.size()*b.size()==0)return vector<int>(0);
    vector<int> c(a.size()+b.size()-1,0);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            c[i+j]+=a[i]*b[j];
        }
    }
    return c;
}
void addTo(vector<int>&a, vector<int>&b,int n){
    if(b.size()==0)return;
    else if(a.size()==0){
        for(int i=0;i<n;i++)a.push_back(0);
        for(int i=0;i<b.size();i++)a.push_back(b[i]);
        return ;
    }
    for(int i=a.size();i<b.size()+n;i++)a.push_back(0);
    for(int i=n;i<b.size()+n;i++)a[i]+=b[i-n];
}
void subTo(vector<int>&a, vector<int>&b){
    if(b.size()==0)return;
    else if(a.size()==0){
        for(int i=0;i<b.size();i++)a.push_back(-b[i]);return;
    }
    for(int i=a.size();i<b.size();i++)a.push_back(0);
    for(int i=0;i<b.size();i++)a[i]-=b[i];
}

vector<int> karatsuba(vector<int>&a, vector<int>&b){
    if(b.size()*a.size()==0)return vector<int>(0);
    if(a.size()<500)return multi(a,b);
    int half=a.size()/2;
    vector<int> a0(a.begin(),a.begin()+half), a1(a.begin()+half,a.end());
    vector<int> b0(b.begin(),b.begin()+(half<b.size()?half:b.size())), b1(b.begin()+(half<b.size()?half:b.size()),b.end());
    vector<int> z1=karatsuba(a1,b1),z0=karatsuba(a0,b0);
    subTo(a1,a0);subTo(b1,b0);
    vector<int> temp=karatsuba(a1,b1);
    vector<int> z2;addTo(z2,z1,0);addTo(z2,z0,0);subTo(z2,temp);
    vector<int> res;
    addTo(res,z0,0);addTo(res,z2,half);addTo(res,z1,half*2);
    return res;
}
string members,fans;

int main(){
    int C;
    cin>>C;
    while(C--){
        vector<int> m,f;
        cin>>members;int N=members.size();
        cin>>fans;int M=fans.size();
        for(int i=0;i<fans.size();i++){
            if(i<N)m.push_back(members[N-1-i]=='M'?1:0);
            f.push_back(fans[i]=='M'?1:0);
        }
        vector<int> res=karatsuba(f,m);
        int out=0;
        for(int i=N-1;i<M;i++)if(res[i]==0)out++;
        cout<<out<<endl;
    }
    return 0;
}
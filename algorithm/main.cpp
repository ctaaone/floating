#include <iostream>
#include <vector>
#include <string>

using namespace std;

int C, N, M;
string members, fans;
vector<int> m,f;

void normal(vector<int>&a){
    while(a.back()==0)a.pop_back();
}
vector<int> addTo(vector<int>&a, vector<int>&b,int n){
    int max_size = (a.size()+n)>b.size()?a.size()+n:b.size();
    vector<int> c(max_size);
    for(int i=0;i<n;i++)c.push_back((b.size()<=i?0:b[i]));
    for(int i=n;i<max_size;i++)c.push_back((a.size()<=i?0:a[i-n])+(b.size()<=i?0:b[i]));
    normal(c);
    return c;
}
vector<int> subTo(vector<int>&a, vector<int>&b){
    int max_size = a.size()>b.size()?a.size():b.size();
    vector<int> c(max_size);
    for(int i=0;i<max_size;i++)c.push_back((a.size()<=i?0:a[i])-(b.size()<=i?0:b[i]));
    normal(c);
    return c;
}

vector<int> mul(vector<int>&a, vector<int>b){
    vector<int> c(a.size()+b.size(),0);
    for(int i=0;i<b.size();i++){
        for(int j=0;j<a.size();j++){
            c[i+j]+=a[j]*b[i];
        }
    }
    if(c.back()==0)c.pop_back();
    return c;
}
vector<int> karatsuba(vector<int>& a, vector<int>&b){
    for(int i=a.size()-1;i>=0;i--)cout<<a[i];cout<<endl;
    for(int i=b.size()-1;i>=0;i--)cout<<b[i];cout<<endl;
    if(a.empty()||b.empty())return vector<int>(0);
    if(a.size()<10)return mul(a,b);
    int half=a.size()/2;
    vector<int> a0(a.begin(),a.begin()+half),a1(a.begin()+half,a.end());
    vector<int> b0(b.begin(),b.begin()+(half>b.size()?b.size():half)),b1(b.begin()+(half>b.size()?b.size():half),b.end());

    vector<int> z0=karatsuba(a1,b1),z1=karatsuba(a0,b0);
    vector<int> z2;
    z2=addTo(z1,z0,0);
    vector<int> a2=subTo(a1,a0),b2=subTo(b1,b0);
    vector<int> res=karatsuba(a2,b2);
    z2=subTo(z2,res);
    res=addTo(z0,z1,half);
    res=addTo(res,z2,half);
    return res; 
}



int main()
{
    cin>>C;
    while(C--){
        /*cin>>members;
        cin>>fans;
        N=members.size();
        M=fans.size();
        for(int i=0;i<M;i++){
            f.push_back(fans[i]=='F'?1:0);
            if(i<N)m.push_back(members[N-i-1]=='F'?1:0);
        }
        vector<int> result=karatsuba(f,m);
        int out=0;
        for(int i=N-1;i<2*N-1;i++){
            if(result[i]==N)out++;
        }
        cout<<out<<endl;*/
        vector<int> a={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},b={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,2};
        vector<int> out=karatsuba(a,b);
        for(int i=0;i<out.size();i++)cout<<out[i];       
    }
    return 0;
}
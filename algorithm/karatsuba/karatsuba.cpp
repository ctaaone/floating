#include <vector>
#include <stdlib.h>
using namespace std;

void karatsuba_normalize(vector<int>& num){
    num.push_back(0);
    for(int i=0;i+1<num.size();i++){
        if(num[i]<0){
            int borrow=(abs(num[i]+9)/10);
            num[i+1]-=borrow;
            num[i]+=borrow*10;
        }else{
            num[i+1]+=num[i]/10;
            num[i]%=10;
        }
    }
    while(num.back()==0&&num.size()>1)num.pop_back();
}

void karatsuba_addTo(vector<int>& a, const vector<int>& b, int k){//a+=b*(10^k)
    while(a.size()<b.size()+k)
        a.push_back(0);
    for(int i=0;i<b.size();i++)
        a[i+k]+=b[i];
    karatsuba_normalize(a);
}
void karatsuba_subFrom(vector<int>&a, const vector<int>&b){
    for(int i=0;i<b.size();i++)
        a[i]-=b[i];
    karatsuba_normalize(a);
}
vector<int> karatsuba_multiply(const vector<int>&a, const vector<int> &b){
    vector<int> c(a.size()+b.size()+1,0);
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++)
            c[i+j]+=a[i]*b[j];
    karatsuba_normalize(c);
    return c;
}
vector<int> karatsuba(const vector<int>& a, const vector<int>& b){//a.size()>b.size
    int an=a.size(),bn=b.size();
    if(an<bn) return karatsuba(b,a);
    if(bn==0)return vector<int>();
    if(an<=50)return karatsuba_multiply(a,b);
    int half=an/2;
    vector<int> a0(a.begin(), a.begin()+half);
    vector<int> a1(a.begin()+half, a.end());
    vector<int> b0(b.begin(), b.begin()+min<int>(b.size(),half));
    vector<int> b1(b.begin()+min<int>(b.size(),half), b.end());
    vector<int> z0=karatsuba(a0, b0);
    vector<int> z2=karatsuba(a1, b1);
    karatsuba_addTo(a0,a1,0);karatsuba_addTo(b0,b1,0);
    vector<int> z1=karatsuba(a0,b0);
    karatsuba_subFrom(z1, z0);karatsuba_subFrom(z1, z2);
    vector<int> ret;
    karatsuba_addTo(ret, z0, 0);
    karatsuba_addTo(ret, z1, half);
    karatsuba_addTo(ret, z2, half+half);
    return ret;
}
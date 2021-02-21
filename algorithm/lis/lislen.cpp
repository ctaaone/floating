/*lislen(lis 길이 찾고자 하는 vector<int>
return lis 길이*/
#pragma once
#include <iostream>
#include <vector>
using namespace std;

int lis_find(int data,int f,const vector<int>& cache){//a와 b 사이에 data가 존재한다면 b의 인덱스를 반환
    int s=0,e=f,h,me=f;
    if(cache[0]>data)return 0;
    while(s+1<e){
        h=(s+e)/2;
        if(cache[h]>=data){         //같은 데이터가 있다는 건 data 값이 의미가 없다는 거(전에 있던 애보다 더 긴 걸 못만든다)
            e=h;if(e<me)me=e;
        }else{
            s=h;
        }
    }
    if(s==0)return 1;
    else return me;
}

int lislen(const vector<int>& arr){
    vector<int> cache(arr.size());
    cache[0]=arr[0];int ma=1;       //[,)
    for(int n=1;n<arr.size();n++){
        int i=lis_find(arr[n],ma,cache);if(i==ma)ma++;
        cache[i]=arr[n];
    }
    return ma;
}
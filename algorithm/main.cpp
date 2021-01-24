#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;
#define FOR(i,n) for(int i=0;(i)<(n);i++)

void printPicked(vector<int>& picked){
    for(int i=0;i<picked.size();i++)printf("%d ",picked[i]);
    printf("\n");
}

void pick(int n, vector<int>& picked, int toPick){
    if (toPick==0){printPicked(picked);return;}
    int smallest = picked.empty()?0:picked.back()+1;
    for(int i=smallest;i<n;i++){
        picked.push_back(i);
        pick(n,picked,toPick-1);
        picked.pop_back();
    }
}

int main(){
    int i;vector<int> picked;
    pick(10,picked,5);
    return 0;
}
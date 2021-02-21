#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main(){
    int r,c, rs, re;
    cout<<"row ";
    cin>>r;
    cout<<"column ";
    cin>>c;
    cout<<"range ";
    cin>>rs>>re;
    srand((int)time(NULL));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<((int)rand())%(re-rs+1)+rs<<"\t";
        }cout<<endl;
    }return 0;
}
#include <stdio.h>
#include <vector>

using namespace std;

#define FOR(i,n) for(int i=0;i<(n);i++)

char link[16][10]={
    
};
vector<int> clock;

int solve(vector<int>& clock){

}

int main(){
    int C,temp;
    scanf("%d",&C);
    while(C--){
        FOR(i,16){scanf("%d",&temp);clock.push_back(4-temp/3%4);}

    }
    return 0;
}
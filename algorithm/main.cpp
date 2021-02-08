#include <stdio.h>
#include "string.h"

char str[1001];

int solve(int s){//[s,e)
    int index[5],i=s+1,c=0;
    while(c<4){
        if(str[i]=='x'){
            index[c++]=i;
            index[c]=solve(i);
        }else {
            index[c++]=i;
            index[c]=i+1;
        }
        i=index[c];
    }
    char temp[1001];
    strncpy(temp,str+index[0],index[2]-index[0]);
    strncpy(str+index[0],str+index[2],index[4]-index[2]);
    strncpy(str+index[4]-index[2]+index[0],temp,index[2]-index[0]);
    return i;
}

int main(){
    int C;
    scanf("%d",&C);
    while(C--){
        scanf("%s",str);
        if(str[0]=='x')
        solve(0);
        printf("%s\n",str);
    }
    return 0;
}
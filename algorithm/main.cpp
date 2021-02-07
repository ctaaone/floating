#include <stdio.h>
#include "string.h"

char str[1001];

void solve(int s, int e){//[s,e)
    if(str[s]!='x')return;
    char temp[1001]={0};int sc=0,pc=0,sa[4],ea[4],i=s+1;
    while(sc<4&&i<e){//sa 찾기
        if(str[i]=='x'&&pc==0){sa[sc++]=i;pc+=4;}
        else if(str[i]=='x')pc+=3;
        else {
            if(pc==0)sa[sc++]=i;
            else pc--;
        }
        i++;
    }
    for(int i=0;i<3;i++)ea[i]=sa[i+1];ea[3]=e;
    for(int i=0;i<4;i++)solve(sa[i],ea[i]);
    for(int i=2;i<6;i++){strncat(temp, str+sa[i%4], sizeof(char)*(ea[i%4]-sa[i%4]));}
    strncpy(str+s+1,temp, sizeof(char)*strlen(temp));
}

int main(){
    int C;
    scanf("%d",&C);
    while(C--){
        scanf("%s",str);
        solve(0,strlen(str));
        printf("%s\n",str);
    }
    return 0;
}
#include <stdio.h>
#include <time.h>

int fastsum(int n){
    if(n==1)return 1;
    if(n%2==1)return fastsum(n-1)+n;
    return (n*n)/4+2*fastsum(n/2);
}

int sum(int n){
    int ret=0;
    for(int i=0;i<n;i++)ret+=i+1;
    return ret;
}

int main(){
    int n,r;clock_t s,e;
    scanf("%d",&n);
    s=clock();
    r=fastsum(n);
    e=clock();
    printf("%d\n%.0lfms\n",r,(double)(e-s));
    s=clock();
    r=sum(n);
    e=clock();
    printf("%d\n%.0lfms\n",r,(double)(e-s));
    return 0;
}
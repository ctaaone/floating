#include <stdio.h>
#include <stdlib.h>
 
int compare(const void * a,const void * b){
    if (*(long long*)a==*(long long*)b)return 0;
    return *(long long*)a<*(long long*)b?-1:1;
}
 
int main(){
    int n;long long*B;int i=0;
    scanf("%d",&n);
    B=(long long*)malloc(n*sizeof(long long));
    for(i=0;i<n;i++){
        scanf("%lld",B+i);
    }
    qsort(B,n,sizeof(long long),compare);
    printf("%d ",(int)B[0]);
    for(i=1;i<n;i++)printf("%d ",(int)(B[i]-B[i-1]));
    return 0;
}
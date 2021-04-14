#include <iostream>
#include <memory.h>

using namespace std;


int func1(){
	return 1;
}

int main(){
	int (*F)() = func1;
	printf("%p\n",F);
	for(int i=0;i<12;i++)printf("%02X",((unsigned char *)F)[i]);
	//((unsigned char*)F)[5] = (unsigned char)2;
	printf("\n%d", func1());
	return 0;
}
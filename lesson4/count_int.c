#include <stdio.h>

int count_int(unsigned int a)
{
	int result = 0;

	while(a){
		if(a & 0x1){
			result++;
		}
		a>>=1;
	}

	return result;
}

int main()
{
	unsigned int a = 0xf3;

	printf("the %x space num'1s is %d\n",a,count_int(a));

	return 0;
}

#include <stdio.h>

int convert(unsigned int num)
{
	int res = 0;
	int tmp = 0;

	while(num){
		tmp = num % 10;
		res = (res * 10) + tmp;
		num /= 10;
	}

	return res;
}

int main()
{
	int a = 71265;
	printf("the org data is %d,the convert data is %d\n",a,convert(a));

	return 0;
}

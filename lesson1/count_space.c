#include <stdio.h>

int count_space(const char *str)
{
	int result = 0;

	if(str == NULL)
		return -1;

	while(*str){
		if(*str == ' '){
			result++;
		}
		str++;
	}

	return result;
}

int main()
{
	char *str = "h  e llo wor ld";

	printf("the space num is %d\n",count_space(str));

	return 0;
}
